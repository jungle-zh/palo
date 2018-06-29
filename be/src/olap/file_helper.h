// Copyright (c) 2017, Baidu.com, Inc. All Rights Reserved

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef BDG_PALO_BE_SRC_OLAP_FILE_HELPER_H
#define BDG_PALO_BE_SRC_OLAP_FILE_HELPER_H

#include <stdio.h>
#include <sys/stat.h>
 
#include <memory>
#include <string>
#include <vector>

#include "olap/lru_cache.h"
#include "olap/olap_common.h"
#include "olap/olap_define.h"
#include "olap/utils.h"

namespace palo {

typedef struct FileDescriptor {
    int fd;
    FileDescriptor(int fd) : fd(fd) {}
    ~FileDescriptor() {
        ::close(fd);
    }
} FileDescriptor;

class FileHandler {
public:
    FileHandler();
    ~FileHandler();

    OLAPStatus open(const std::string& file_name, int flag);
    OLAPStatus open_with_cache(const std::string& file_name, int flag);
    // The argument mode specifies the permissions to use in case a new file is created.
    OLAPStatus open_with_mode(const std::string& file_name, int flag, int mode);
    OLAPStatus close();
    OLAPStatus release();

    OLAPStatus pread(void* buf, size_t size, size_t offset);
    OLAPStatus write(const void* buf, size_t buf_size);
    OLAPStatus pwrite(const void* buf, size_t buf_size, size_t offset);

    int32_t sync() {
        return 0;
    }

    off_t tell() const {
        off_t res = -1;

        if (-1 == (res = lseek(_fd, 0, SEEK_CUR))) {
            OLAP_LOG_WARNING("fail to tell file. [err=%m file_name='%s' fd=%d]",
                             _file_name.c_str(), _fd);
        }

        return res;
    }

    off_t length() const;

    off_t seek(off_t offset, int whence) {
        off_t res = -1;

        if (-1 == (res = lseek(_fd, offset, whence))) {
            OLAP_LOG_WARNING("fail to seek file. [err=%m file_name='%s' fd=%d "
                             "offset=%ld whence=%d]",
                             _file_name.c_str(), _fd, offset, whence);
        }

        return res;
    }

    const std::string& file_name() {
        return _file_name;
    }

    int fd() {
        return _fd;
    }

    static void _delete_cache_file_descriptor(const CacheKey& key, void* value) {
        FileDescriptor* file_desc = reinterpret_cast<FileDescriptor*>(value);
        SAFE_DELETE(file_desc);
    }

private:
    int _fd;
    off_t _wr_length;
    const int64_t _cache_threshold = 1<<19;
    std::string _file_name;
    bool _is_using_cache;
    Cache::Handle* _cache_handle;
    Cache* _fd_cache;
};

class FileHandlerWithBuf {
public:
    FileHandlerWithBuf();
    ~FileHandlerWithBuf();

    OLAPStatus open(const std::string &file_name, const char *mode);
    // The argument mode specifies the permissions to use in case a new file is created.
    OLAPStatus open_with_mode(const std::string &file_name, const char *mode);
    OLAPStatus close();

    OLAPStatus read(void *buf, size_t size);
    OLAPStatus pread(void *buf, size_t size, size_t offset);
    OLAPStatus write(const void *buf, size_t buf_size);
    OLAPStatus pwrite(const void *buf, size_t buf_size, size_t offset);

    int32_t sync() {
        int32_t res = -1;
        if (0 != (res = ::fflush(_fp))) {
            OLAP_LOG_WARNING("fail to fsync file. [err=%m file_name='%s']",
                    _file_name.c_str());
        } 
        return res;
    }
    
    off_t tell() const {
        off_t res = -1;
        if (-1 == (res = ::ftell(_fp))) {
            OLAP_LOG_WARNING("fail to tell file. [err=%m file_name='%s']",
                    _file_name.c_str());
        }
        return res;
    }
    
    off_t length() const;
    
    off_t seek(off_t offset, int whence) {
        off_t res = -1;
        if (-1 == (res = ::fseek(_fp, offset, whence))) {
            OLAP_LOG_WARNING("fail to seek file. [err=%m file_name='%s' "
                    "offset=%ld whence=%d]",
                    _file_name.c_str(), offset, whence);
        }
        return res;
    }

    const std::string& file_name() { return _file_name; }
    
    int fd() { return ::fileno(_fp); }

private:
    FILE *_fp;
    std::string _file_name;
};

typedef struct _FixedFileHeader {
    // 整个文件的长度
    uint32_t file_length;
    // 文件除了FileHeader之外的内容的checkcum
    uint32_t checksum;
    // Protobuf部分的长度
    uint32_t protobuf_length;
    // Protobuf部分的checksum
    uint32_t protobuf_checksum;
} __attribute__((packed)) FixedFileHeader;

typedef struct _FixedFileHeaderV2 {
    uint64_t magic_number;
    uint32_t version;
    // 整个文件的长度
    uint64_t file_length;
    // 文件除了FileHeader之外的内容的checkcum
    uint32_t checksum;
    // Protobuf部分的长度
    uint64_t protobuf_length;
    // Protobuf部分的checksum
    uint32_t protobuf_checksum;
} __attribute__((packed)) FixedFileHeaderV2;

template <typename MessageType, typename ExtraType = uint32_t, 
          typename FileHandlerType = FileHandler>
class FileHeader {
public:
    FileHeader() {
        memset(&_fixed_file_header, 0, sizeof(_fixed_file_header));
        memset(&_extra_fixed_header, 0, sizeof(_extra_fixed_header));
        _fixed_file_header_size = sizeof(_fixed_file_header);
    }
    ~FileHeader() {}

    // 计算proto部分的长度, 需要在操作完proto之后调用，调用serialize之前必须先prepare
    OLAPStatus prepare(FileHandlerType* file_handler);

    // call prepare() first, serialize() will write fixed header and protobuffer.
    // 把Header写入传入的文件句柄的起始位置
    OLAPStatus serialize(FileHandlerType* file_handler);

    // read from file, validate file length, signature and alder32 of protobuffer.
    // 从传入的文件句柄的起始位置读出Header
    OLAPStatus unserialize(FileHandlerType* file_handler);

    // 校验Header的有效性
    // it is actually call unserialize().
    OLAPStatus validate(const std::string& filename);

    uint64_t file_length() const {
        return _fixed_file_header.file_length;
    }
    uint32_t checksum() const {
        return _fixed_file_header.checksum;
    }
    const ExtraType& extra() const {
        return _extra_fixed_header;
    }
    ExtraType* mutable_extra() {
        return &_extra_fixed_header;
    }
    const MessageType& message() const {
        return _proto;
    }
    MessageType* mutable_message() {
        return &_proto;
    }
    uint64_t size() const {
        return _fixed_file_header_size + sizeof(_extra_fixed_header)
               + _fixed_file_header.protobuf_length;
    }

    void set_file_length(uint64_t file_length) {
        _fixed_file_header.file_length = file_length;
    }
    void set_checksum(uint32_t checksum) {
        _fixed_file_header.checksum = checksum;
    }

private:
    FixedFileHeaderV2 _fixed_file_header;
    uint32_t _fixed_file_header_size;

    std::string _proto_string;
    ExtraType _extra_fixed_header;
    MessageType _proto;
};

// FileHandler implementation
template <typename MessageType, typename ExtraType, typename FileHandlerType>   //jungle comment:FileHeader is data file header or index file header,in load_pb() ,MessageType is ColumnDataHeaderMessage
OLAPStatus FileHeader<MessageType, ExtraType, FileHandlerType>::prepare(
        FileHandlerType* file_handler) {
    if (NULL == file_handler) {
        return OLAP_ERR_INPUT_PARAMETER_ERROR;
    }

    // 把文件名作为Signature, 防止一些运维误操作带来的问题
    // _proto.set_signature(basename(file_handler->file_name().c_str()));

    try {
        if (!_proto.SerializeToString(&_proto_string)) {
            OLAP_LOG_WARNING("serialize file header to string error. [path='%s']",
                             file_handler->file_name().c_str());
            return OLAP_ERR_SERIALIZE_PROTOBUF_ERROR;
        }
    } catch (...) {
        OLAP_LOG_WARNING("serialize file header to string error. [path='%s']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_SERIALIZE_PROTOBUF_ERROR;
    }

    _fixed_file_header.protobuf_checksum = olap_adler32(ADLER32_INIT,
                                           _proto_string.c_str(), _proto_string.size());

    _fixed_file_header.checksum = 0;
    _fixed_file_header.protobuf_length = _proto_string.size();
    _fixed_file_header.file_length = size();
    _fixed_file_header.version = OLAP_DATA_VERSION_APPLIED;
    _fixed_file_header.magic_number = OLAP_FIX_HEADER_MAGIC_NUMBER;

    return OLAP_SUCCESS;
}

template <typename MessageType, typename ExtraType, typename FileHandlerType>
OLAPStatus FileHeader<MessageType, ExtraType, FileHandlerType>::serialize(      //jungle comment MessageType maybe OLAPIndexHeaderMessage ,or ColumnDataHeaderMessage
        FileHandlerType* file_handler) {
    if (NULL == file_handler) {
        return OLAP_ERR_INPUT_PARAMETER_ERROR;
    }

    // 写入文件
    if (OLAP_SUCCESS != file_handler->pwrite(&_fixed_file_header,  //jungle comment : _current_file_handler.seek
            _fixed_file_header_size, 0)) {
        OLAP_LOG_WARNING("fail to write fixed header to file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    if (OLAP_SUCCESS != file_handler->pwrite(&_extra_fixed_header, sizeof(_extra_fixed_header),
            _fixed_file_header_size)) {
        OLAP_LOG_WARNING("fail to write extra fixed header to file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    if (OLAP_SUCCESS != file_handler->pwrite(_proto_string.c_str(), _proto_string.size(),
            _fixed_file_header_size + sizeof(_extra_fixed_header))) {
        OLAP_LOG_WARNING("fail to write proto header to file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    return OLAP_SUCCESS;
}

template <typename MessageType, typename ExtraType, typename FileHandlerType>
OLAPStatus FileHeader<MessageType, ExtraType, FileHandlerType>::unserialize(
        FileHandlerType* file_handler) {
    if (NULL == file_handler) {
        return OLAP_ERR_INPUT_PARAMETER_ERROR;
    }

    off_t real_file_length = 0;
    uint32_t real_protobuf_checksum = 0;

    if (OLAP_SUCCESS != file_handler->pread(&_fixed_file_header,
                                            _fixed_file_header_size, 0)) {
        OLAP_LOG_WARNING("fail to load header structure from file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    if (_fixed_file_header.magic_number != OLAP_FIX_HEADER_MAGIC_NUMBER) {
        OLAP_LOG_TRACE("old fix header found, magic num = [%lu]",
                       _fixed_file_header.magic_number);

        FixedFileHeader tmp_header;

        if (OLAP_SUCCESS != file_handler->pread(&tmp_header,
                                                sizeof(tmp_header), 0)) {
            OLAP_LOG_WARNING("fail to load header structure from file. [file='%s' message='%m']",
                             file_handler->file_name().c_str());
            return OLAP_ERR_IO_ERROR;
        }

        _fixed_file_header.file_length = tmp_header.file_length;
        _fixed_file_header.checksum = tmp_header.checksum;
        _fixed_file_header.protobuf_length = tmp_header.protobuf_length;
        _fixed_file_header.protobuf_checksum = tmp_header.protobuf_checksum;
        _fixed_file_header.magic_number = OLAP_FIX_HEADER_MAGIC_NUMBER;
        _fixed_file_header.version = OLAP_DATA_VERSION_APPLIED;

        _fixed_file_header_size = sizeof(tmp_header);
    }

    OLAP_LOG_DEBUG("fix head loaded. [file_length = %lu, checksum = %d, "
                   "protobuf_length = %lu, proto_checksum = %u, "
                   "magic_number = %lu, version = %d",
                   _fixed_file_header.file_length, _fixed_file_header.checksum,
                   _fixed_file_header.protobuf_length, _fixed_file_header.protobuf_checksum,
                   _fixed_file_header.magic_number, _fixed_file_header.version);

    if (OLAP_SUCCESS != file_handler->pread(&_extra_fixed_header,
            sizeof(_extra_fixed_header), _fixed_file_header_size)) {
        OLAP_LOG_WARNING("fail to load extra fixed header from file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    std::unique_ptr<char[]> buf(new(std::nothrow) char[_fixed_file_header.protobuf_length]);

    if (NULL == buf.get()) {
        OLAP_LOG_WARNING("malloc protobuf buf error. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_MALLOC_ERROR;
    }

    if (OLAP_SUCCESS != file_handler->pread(buf.get(), _fixed_file_header.protobuf_length,
            _fixed_file_header_size + sizeof(_extra_fixed_header))) {
        OLAP_LOG_WARNING("fail to load protobuf from file. [file='%s' message='%m']",
                         file_handler->file_name().c_str());
        return OLAP_ERR_IO_ERROR;
    }

    real_file_length = file_handler->length();

    if (file_length() != static_cast<uint64_t>(real_file_length)) {
        OLAP_LOG_WARNING("file length is not match. [file='%s' file_length=%lu"
                         " real_file_length=%ld]",
                         file_handler->file_name().c_str(), file_length(), real_file_length);
        return OLAP_ERR_FILE_DATA_ERROR;
    }

    // check proto checksum
    real_protobuf_checksum = olap_adler32(ADLER32_INIT,
                                          buf.get(), _fixed_file_header.protobuf_length);

    if (real_protobuf_checksum != _fixed_file_header.protobuf_checksum) {
        OLAP_LOG_WARNING("checksum is not match. [file='%s' expect=%d actual=%d]",
                         file_handler->file_name().c_str(),
                         _fixed_file_header.protobuf_checksum,
                         real_protobuf_checksum);
        return OLAP_ERR_CHECKSUM_ERROR;
    }

    try {
        std::string protobuf_str(buf.get(), _fixed_file_header.protobuf_length);

        if (!_proto.ParseFromString(protobuf_str)) {
            OLAP_LOG_WARNING("fail to parse file content to protobuf object. [file='%s']",
                             file_handler->file_name().c_str());
            return OLAP_ERR_PARSE_PROTOBUF_ERROR;
        }
    } catch (...) {
        OLAP_LOG_WARNING("fail to load protobuf. [file='%s']", file_handler->file_name().c_str());
        return OLAP_ERR_PARSE_PROTOBUF_ERROR;
    }

    return OLAP_SUCCESS;
}

template <typename MessageType, typename ExtraType, typename FileHandlerType>
OLAPStatus FileHeader<MessageType, ExtraType, FileHandlerType>::validate(
        const std::string& filename) {
    FileHandler file_handler;
    OLAPStatus res = OLAP_SUCCESS;

    if (OLAP_SUCCESS != file_handler.open(filename.c_str(), O_RDONLY)) {
        OLAP_LOG_WARNING("fail to open file. [file='%s' message='%m']",
                         filename.c_str());
        return OLAP_ERR_IO_ERROR;
    }

    if (OLAP_SUCCESS != (res = unserialize(&file_handler))) {
        OLAP_LOG_WARNING("unserialize file header error. [file='%s']", filename.c_str());
        return res;
    }

    return OLAP_SUCCESS;
}

}  // namespace palo

#endif // BDG_PALO_BE_SRC_OLAP_FILE_HELPER_H
