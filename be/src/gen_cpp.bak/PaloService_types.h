/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef PaloService_TYPES_H
#define PaloService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Status_types.h"


namespace palo {

struct TPaloQueryOptions {
  enum type {
    ABORT_ON_ERROR = 0,
    MAX_ERRORS = 1,
    DISABLE_CODEGEN = 2,
    BATCH_SIZE = 3,
    MEM_LIMIT = 4,
    NUM_NODES = 5,
    MAX_SCAN_RANGE_LENGTH = 6,
    MAX_IO_BUFFERS = 7,
    NUM_SCANNER_THREADS = 8,
    QUERY_TIMEOUT = 9,
    ALLOW_UNSUPPORTED_FORMATS = 10,
    DEFAULT_ORDER_BY_LIMIT = 11,
    DEBUG_ACTION = 12,
    ABORT_ON_DEFAULT_LIMIT_EXCEEDED = 13,
    IS_REPORT_SUCCESS = 14
  };
};

extern const std::map<int, const char*> _TPaloQueryOptions_VALUES_TO_NAMES;

} // namespace

#endif
