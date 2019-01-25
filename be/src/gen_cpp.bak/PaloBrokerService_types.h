/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef PaloBrokerService_TYPES_H
#define PaloBrokerService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace palo {

struct TBrokerOperationStatusCode {
  enum type {
    OK = 0,
    END_OF_FILE = 301,
    NOT_AUTHORIZED = 401,
    DUPLICATE_REQUEST = 402,
    INVALID_INPUT_OFFSET = 403,
    INVALID_INPUT_FILE_PATH = 404,
    INVALID_ARGUMENT = 405,
    FILE_NOT_FOUND = 501,
    TARGET_STORAGE_SERVICE_ERROR = 502,
    OPERATION_NOT_SUPPORTED = 503
  };
};

extern const std::map<int, const char*> _TBrokerOperationStatusCode_VALUES_TO_NAMES;

struct TBrokerVersion {
  enum type {
    VERSION_ONE = 1
  };
};

extern const std::map<int, const char*> _TBrokerVersion_VALUES_TO_NAMES;

struct TBrokerOpenMode {
  enum type {
    APPEND = 1
  };
};

extern const std::map<int, const char*> _TBrokerOpenMode_VALUES_TO_NAMES;

class TBrokerOperationStatus;

class TBrokerFileStatus;

class TBrokerFD;

class TBrokerListResponse;

class TBrokerOpenReaderResponse;

class TBrokerReadResponse;

class TBrokerOpenWriterResponse;

class TBrokerCheckPathExistResponse;

class TBrokerListPathRequest;

class TBrokerDeletePathRequest;

class TBrokerRenamePathRequest;

class TBrokerCheckPathExistRequest;

class TBrokerOpenReaderRequest;

class TBrokerPReadRequest;

class TBrokerSeekRequest;

class TBrokerCloseReaderRequest;

class TBrokerOpenWriterRequest;

class TBrokerPWriteRequest;

class TBrokerCloseWriterRequest;

class TBrokerPingBrokerRequest;

typedef struct _TBrokerOperationStatus__isset {
  _TBrokerOperationStatus__isset() : message(false) {}
  bool message :1;
} _TBrokerOperationStatus__isset;

class TBrokerOperationStatus {
 public:

  TBrokerOperationStatus(const TBrokerOperationStatus&);
  TBrokerOperationStatus& operator=(const TBrokerOperationStatus&);
  TBrokerOperationStatus() : statusCode((TBrokerOperationStatusCode::type)0), message() {
  }

  virtual ~TBrokerOperationStatus() throw();
  TBrokerOperationStatusCode::type statusCode;
  std::string message;

  _TBrokerOperationStatus__isset __isset;

  void __set_statusCode(const TBrokerOperationStatusCode::type val);

  void __set_message(const std::string& val);

  bool operator == (const TBrokerOperationStatus & rhs) const
  {
    if (!(statusCode == rhs.statusCode))
      return false;
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const TBrokerOperationStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerOperationStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerOperationStatus &a, TBrokerOperationStatus &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerOperationStatus& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerFileStatus {
 public:

  TBrokerFileStatus(const TBrokerFileStatus&);
  TBrokerFileStatus& operator=(const TBrokerFileStatus&);
  TBrokerFileStatus() : path(), isDir(0), size(0), isSplitable(0) {
  }

  virtual ~TBrokerFileStatus() throw();
  std::string path;
  bool isDir;
  int64_t size;
  bool isSplitable;

  void __set_path(const std::string& val);

  void __set_isDir(const bool val);

  void __set_size(const int64_t val);

  void __set_isSplitable(const bool val);

  bool operator == (const TBrokerFileStatus & rhs) const
  {
    if (!(path == rhs.path))
      return false;
    if (!(isDir == rhs.isDir))
      return false;
    if (!(size == rhs.size))
      return false;
    if (!(isSplitable == rhs.isSplitable))
      return false;
    return true;
  }
  bool operator != (const TBrokerFileStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerFileStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerFileStatus &a, TBrokerFileStatus &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerFileStatus& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerFD {
 public:

  TBrokerFD(const TBrokerFD&);
  TBrokerFD& operator=(const TBrokerFD&);
  TBrokerFD() : high(0), low(0) {
  }

  virtual ~TBrokerFD() throw();
  int64_t high;
  int64_t low;

  void __set_high(const int64_t val);

  void __set_low(const int64_t val);

  bool operator == (const TBrokerFD & rhs) const
  {
    if (!(high == rhs.high))
      return false;
    if (!(low == rhs.low))
      return false;
    return true;
  }
  bool operator != (const TBrokerFD &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerFD & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerFD &a, TBrokerFD &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerFD& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TBrokerListResponse__isset {
  _TBrokerListResponse__isset() : files(false) {}
  bool files :1;
} _TBrokerListResponse__isset;

class TBrokerListResponse {
 public:

  TBrokerListResponse(const TBrokerListResponse&);
  TBrokerListResponse& operator=(const TBrokerListResponse&);
  TBrokerListResponse() {
  }

  virtual ~TBrokerListResponse() throw();
  TBrokerOperationStatus opStatus;
  std::vector<TBrokerFileStatus>  files;

  _TBrokerListResponse__isset __isset;

  void __set_opStatus(const TBrokerOperationStatus& val);

  void __set_files(const std::vector<TBrokerFileStatus> & val);

  bool operator == (const TBrokerListResponse & rhs) const
  {
    if (!(opStatus == rhs.opStatus))
      return false;
    if (__isset.files != rhs.__isset.files)
      return false;
    else if (__isset.files && !(files == rhs.files))
      return false;
    return true;
  }
  bool operator != (const TBrokerListResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerListResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerListResponse &a, TBrokerListResponse &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerListResponse& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TBrokerOpenReaderResponse__isset {
  _TBrokerOpenReaderResponse__isset() : fd(false) {}
  bool fd :1;
} _TBrokerOpenReaderResponse__isset;

class TBrokerOpenReaderResponse {
 public:

  TBrokerOpenReaderResponse(const TBrokerOpenReaderResponse&);
  TBrokerOpenReaderResponse& operator=(const TBrokerOpenReaderResponse&);
  TBrokerOpenReaderResponse() {
  }

  virtual ~TBrokerOpenReaderResponse() throw();
  TBrokerOperationStatus opStatus;
  TBrokerFD fd;

  _TBrokerOpenReaderResponse__isset __isset;

  void __set_opStatus(const TBrokerOperationStatus& val);

  void __set_fd(const TBrokerFD& val);

  bool operator == (const TBrokerOpenReaderResponse & rhs) const
  {
    if (!(opStatus == rhs.opStatus))
      return false;
    if (__isset.fd != rhs.__isset.fd)
      return false;
    else if (__isset.fd && !(fd == rhs.fd))
      return false;
    return true;
  }
  bool operator != (const TBrokerOpenReaderResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerOpenReaderResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerOpenReaderResponse &a, TBrokerOpenReaderResponse &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerOpenReaderResponse& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TBrokerReadResponse__isset {
  _TBrokerReadResponse__isset() : data(false) {}
  bool data :1;
} _TBrokerReadResponse__isset;

class TBrokerReadResponse {
 public:

  TBrokerReadResponse(const TBrokerReadResponse&);
  TBrokerReadResponse& operator=(const TBrokerReadResponse&);
  TBrokerReadResponse() : data() {
  }

  virtual ~TBrokerReadResponse() throw();
  TBrokerOperationStatus opStatus;
  std::string data;

  _TBrokerReadResponse__isset __isset;

  void __set_opStatus(const TBrokerOperationStatus& val);

  void __set_data(const std::string& val);

  bool operator == (const TBrokerReadResponse & rhs) const
  {
    if (!(opStatus == rhs.opStatus))
      return false;
    if (__isset.data != rhs.__isset.data)
      return false;
    else if (__isset.data && !(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const TBrokerReadResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerReadResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerReadResponse &a, TBrokerReadResponse &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerReadResponse& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TBrokerOpenWriterResponse__isset {
  _TBrokerOpenWriterResponse__isset() : fd(false) {}
  bool fd :1;
} _TBrokerOpenWriterResponse__isset;

class TBrokerOpenWriterResponse {
 public:

  TBrokerOpenWriterResponse(const TBrokerOpenWriterResponse&);
  TBrokerOpenWriterResponse& operator=(const TBrokerOpenWriterResponse&);
  TBrokerOpenWriterResponse() {
  }

  virtual ~TBrokerOpenWriterResponse() throw();
  TBrokerOperationStatus opStatus;
  TBrokerFD fd;

  _TBrokerOpenWriterResponse__isset __isset;

  void __set_opStatus(const TBrokerOperationStatus& val);

  void __set_fd(const TBrokerFD& val);

  bool operator == (const TBrokerOpenWriterResponse & rhs) const
  {
    if (!(opStatus == rhs.opStatus))
      return false;
    if (__isset.fd != rhs.__isset.fd)
      return false;
    else if (__isset.fd && !(fd == rhs.fd))
      return false;
    return true;
  }
  bool operator != (const TBrokerOpenWriterResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerOpenWriterResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerOpenWriterResponse &a, TBrokerOpenWriterResponse &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerOpenWriterResponse& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerCheckPathExistResponse {
 public:

  TBrokerCheckPathExistResponse(const TBrokerCheckPathExistResponse&);
  TBrokerCheckPathExistResponse& operator=(const TBrokerCheckPathExistResponse&);
  TBrokerCheckPathExistResponse() : isPathExist(0) {
  }

  virtual ~TBrokerCheckPathExistResponse() throw();
  TBrokerOperationStatus opStatus;
  bool isPathExist;

  void __set_opStatus(const TBrokerOperationStatus& val);

  void __set_isPathExist(const bool val);

  bool operator == (const TBrokerCheckPathExistResponse & rhs) const
  {
    if (!(opStatus == rhs.opStatus))
      return false;
    if (!(isPathExist == rhs.isPathExist))
      return false;
    return true;
  }
  bool operator != (const TBrokerCheckPathExistResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerCheckPathExistResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerCheckPathExistResponse &a, TBrokerCheckPathExistResponse &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerCheckPathExistResponse& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerListPathRequest {
 public:

  TBrokerListPathRequest(const TBrokerListPathRequest&);
  TBrokerListPathRequest& operator=(const TBrokerListPathRequest&);
  TBrokerListPathRequest() : version((TBrokerVersion::type)0), path(), isRecursive(0) {
  }

  virtual ~TBrokerListPathRequest() throw();
  TBrokerVersion::type version;
  std::string path;
  bool isRecursive;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_path(const std::string& val);

  void __set_isRecursive(const bool val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerListPathRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(isRecursive == rhs.isRecursive))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerListPathRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerListPathRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerListPathRequest &a, TBrokerListPathRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerListPathRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerDeletePathRequest {
 public:

  TBrokerDeletePathRequest(const TBrokerDeletePathRequest&);
  TBrokerDeletePathRequest& operator=(const TBrokerDeletePathRequest&);
  TBrokerDeletePathRequest() : version((TBrokerVersion::type)0), path() {
  }

  virtual ~TBrokerDeletePathRequest() throw();
  TBrokerVersion::type version;
  std::string path;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_path(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerDeletePathRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerDeletePathRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerDeletePathRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerDeletePathRequest &a, TBrokerDeletePathRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerDeletePathRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerRenamePathRequest {
 public:

  TBrokerRenamePathRequest(const TBrokerRenamePathRequest&);
  TBrokerRenamePathRequest& operator=(const TBrokerRenamePathRequest&);
  TBrokerRenamePathRequest() : version((TBrokerVersion::type)0), srcPath(), destPath() {
  }

  virtual ~TBrokerRenamePathRequest() throw();
  TBrokerVersion::type version;
  std::string srcPath;
  std::string destPath;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_srcPath(const std::string& val);

  void __set_destPath(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerRenamePathRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(srcPath == rhs.srcPath))
      return false;
    if (!(destPath == rhs.destPath))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerRenamePathRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerRenamePathRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerRenamePathRequest &a, TBrokerRenamePathRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerRenamePathRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerCheckPathExistRequest {
 public:

  TBrokerCheckPathExistRequest(const TBrokerCheckPathExistRequest&);
  TBrokerCheckPathExistRequest& operator=(const TBrokerCheckPathExistRequest&);
  TBrokerCheckPathExistRequest() : version((TBrokerVersion::type)0), path() {
  }

  virtual ~TBrokerCheckPathExistRequest() throw();
  TBrokerVersion::type version;
  std::string path;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_path(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerCheckPathExistRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerCheckPathExistRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerCheckPathExistRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerCheckPathExistRequest &a, TBrokerCheckPathExistRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerCheckPathExistRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerOpenReaderRequest {
 public:

  TBrokerOpenReaderRequest(const TBrokerOpenReaderRequest&);
  TBrokerOpenReaderRequest& operator=(const TBrokerOpenReaderRequest&);
  TBrokerOpenReaderRequest() : version((TBrokerVersion::type)0), path(), startOffset(0), clientId() {
  }

  virtual ~TBrokerOpenReaderRequest() throw();
  TBrokerVersion::type version;
  std::string path;
  int64_t startOffset;
  std::string clientId;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_path(const std::string& val);

  void __set_startOffset(const int64_t val);

  void __set_clientId(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerOpenReaderRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(startOffset == rhs.startOffset))
      return false;
    if (!(clientId == rhs.clientId))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerOpenReaderRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerOpenReaderRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerOpenReaderRequest &a, TBrokerOpenReaderRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerOpenReaderRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerPReadRequest {
 public:

  TBrokerPReadRequest(const TBrokerPReadRequest&);
  TBrokerPReadRequest& operator=(const TBrokerPReadRequest&);
  TBrokerPReadRequest() : version((TBrokerVersion::type)0), offset(0), length(0) {
  }

  virtual ~TBrokerPReadRequest() throw();
  TBrokerVersion::type version;
  TBrokerFD fd;
  int64_t offset;
  int64_t length;

  void __set_version(const TBrokerVersion::type val);

  void __set_fd(const TBrokerFD& val);

  void __set_offset(const int64_t val);

  void __set_length(const int64_t val);

  bool operator == (const TBrokerPReadRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(fd == rhs.fd))
      return false;
    if (!(offset == rhs.offset))
      return false;
    if (!(length == rhs.length))
      return false;
    return true;
  }
  bool operator != (const TBrokerPReadRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerPReadRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerPReadRequest &a, TBrokerPReadRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerPReadRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerSeekRequest {
 public:

  TBrokerSeekRequest(const TBrokerSeekRequest&);
  TBrokerSeekRequest& operator=(const TBrokerSeekRequest&);
  TBrokerSeekRequest() : version((TBrokerVersion::type)0), offset(0) {
  }

  virtual ~TBrokerSeekRequest() throw();
  TBrokerVersion::type version;
  TBrokerFD fd;
  int64_t offset;

  void __set_version(const TBrokerVersion::type val);

  void __set_fd(const TBrokerFD& val);

  void __set_offset(const int64_t val);

  bool operator == (const TBrokerSeekRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(fd == rhs.fd))
      return false;
    if (!(offset == rhs.offset))
      return false;
    return true;
  }
  bool operator != (const TBrokerSeekRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerSeekRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerSeekRequest &a, TBrokerSeekRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerSeekRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerCloseReaderRequest {
 public:

  TBrokerCloseReaderRequest(const TBrokerCloseReaderRequest&);
  TBrokerCloseReaderRequest& operator=(const TBrokerCloseReaderRequest&);
  TBrokerCloseReaderRequest() : version((TBrokerVersion::type)0) {
  }

  virtual ~TBrokerCloseReaderRequest() throw();
  TBrokerVersion::type version;
  TBrokerFD fd;

  void __set_version(const TBrokerVersion::type val);

  void __set_fd(const TBrokerFD& val);

  bool operator == (const TBrokerCloseReaderRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(fd == rhs.fd))
      return false;
    return true;
  }
  bool operator != (const TBrokerCloseReaderRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerCloseReaderRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerCloseReaderRequest &a, TBrokerCloseReaderRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerCloseReaderRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerOpenWriterRequest {
 public:

  TBrokerOpenWriterRequest(const TBrokerOpenWriterRequest&);
  TBrokerOpenWriterRequest& operator=(const TBrokerOpenWriterRequest&);
  TBrokerOpenWriterRequest() : version((TBrokerVersion::type)0), path(), openMode((TBrokerOpenMode::type)0), clientId() {
  }

  virtual ~TBrokerOpenWriterRequest() throw();
  TBrokerVersion::type version;
  std::string path;
  TBrokerOpenMode::type openMode;
  std::string clientId;
  std::map<std::string, std::string>  properties;

  void __set_version(const TBrokerVersion::type val);

  void __set_path(const std::string& val);

  void __set_openMode(const TBrokerOpenMode::type val);

  void __set_clientId(const std::string& val);

  void __set_properties(const std::map<std::string, std::string> & val);

  bool operator == (const TBrokerOpenWriterRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(path == rhs.path))
      return false;
    if (!(openMode == rhs.openMode))
      return false;
    if (!(clientId == rhs.clientId))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const TBrokerOpenWriterRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerOpenWriterRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerOpenWriterRequest &a, TBrokerOpenWriterRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerOpenWriterRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerPWriteRequest {
 public:

  TBrokerPWriteRequest(const TBrokerPWriteRequest&);
  TBrokerPWriteRequest& operator=(const TBrokerPWriteRequest&);
  TBrokerPWriteRequest() : version((TBrokerVersion::type)0), offset(0), data() {
  }

  virtual ~TBrokerPWriteRequest() throw();
  TBrokerVersion::type version;
  TBrokerFD fd;
  int64_t offset;
  std::string data;

  void __set_version(const TBrokerVersion::type val);

  void __set_fd(const TBrokerFD& val);

  void __set_offset(const int64_t val);

  void __set_data(const std::string& val);

  bool operator == (const TBrokerPWriteRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(fd == rhs.fd))
      return false;
    if (!(offset == rhs.offset))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const TBrokerPWriteRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerPWriteRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerPWriteRequest &a, TBrokerPWriteRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerPWriteRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerCloseWriterRequest {
 public:

  TBrokerCloseWriterRequest(const TBrokerCloseWriterRequest&);
  TBrokerCloseWriterRequest& operator=(const TBrokerCloseWriterRequest&);
  TBrokerCloseWriterRequest() : version((TBrokerVersion::type)0) {
  }

  virtual ~TBrokerCloseWriterRequest() throw();
  TBrokerVersion::type version;
  TBrokerFD fd;

  void __set_version(const TBrokerVersion::type val);

  void __set_fd(const TBrokerFD& val);

  bool operator == (const TBrokerCloseWriterRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(fd == rhs.fd))
      return false;
    return true;
  }
  bool operator != (const TBrokerCloseWriterRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerCloseWriterRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerCloseWriterRequest &a, TBrokerCloseWriterRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerCloseWriterRequest& obj)
{
  obj.printTo(out);
  return out;
}


class TBrokerPingBrokerRequest {
 public:

  TBrokerPingBrokerRequest(const TBrokerPingBrokerRequest&);
  TBrokerPingBrokerRequest& operator=(const TBrokerPingBrokerRequest&);
  TBrokerPingBrokerRequest() : version((TBrokerVersion::type)0), clientId() {
  }

  virtual ~TBrokerPingBrokerRequest() throw();
  TBrokerVersion::type version;
  std::string clientId;

  void __set_version(const TBrokerVersion::type val);

  void __set_clientId(const std::string& val);

  bool operator == (const TBrokerPingBrokerRequest & rhs) const
  {
    if (!(version == rhs.version))
      return false;
    if (!(clientId == rhs.clientId))
      return false;
    return true;
  }
  bool operator != (const TBrokerPingBrokerRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TBrokerPingBrokerRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBrokerPingBrokerRequest &a, TBrokerPingBrokerRequest &b);

inline std::ostream& operator<<(std::ostream& out, const TBrokerPingBrokerRequest& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
