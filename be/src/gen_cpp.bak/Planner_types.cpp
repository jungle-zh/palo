/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Planner_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace palo {


TPlanFragment::~TPlanFragment() throw() {
}


void TPlanFragment::__set_plan(const  ::palo::TPlan& val) {
  this->plan = val;
__isset.plan = true;
}

void TPlanFragment::__set_output_exprs(const std::vector< ::palo::TExpr> & val) {
  this->output_exprs = val;
__isset.output_exprs = true;
}

void TPlanFragment::__set_output_sink(const  ::palo::TDataSink& val) {
  this->output_sink = val;
__isset.output_sink = true;
}

void TPlanFragment::__set_partition(const  ::palo::TDataPartition& val) {
  this->partition = val;
}

uint32_t TPlanFragment::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_partition = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->plan.read(iprot);
          this->__isset.plan = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->output_exprs.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->output_exprs.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->output_exprs[_i4].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.output_exprs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->output_sink.read(iprot);
          this->__isset.output_sink = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->partition.read(iprot);
          isset_partition = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_partition)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TPlanFragment::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TPlanFragment");

  if (this->__isset.plan) {
    xfer += oprot->writeFieldBegin("plan", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->plan.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.output_exprs) {
    xfer += oprot->writeFieldBegin("output_exprs", ::apache::thrift::protocol::T_LIST, 4);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->output_exprs.size()));
      std::vector< ::palo::TExpr> ::const_iterator _iter5;
      for (_iter5 = this->output_exprs.begin(); _iter5 != this->output_exprs.end(); ++_iter5)
      {
        xfer += (*_iter5).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.output_sink) {
    xfer += oprot->writeFieldBegin("output_sink", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->output_sink.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("partition", ::apache::thrift::protocol::T_STRUCT, 6);
  xfer += this->partition.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TPlanFragment &a, TPlanFragment &b) {
  using ::std::swap;
  swap(a.plan, b.plan);
  swap(a.output_exprs, b.output_exprs);
  swap(a.output_sink, b.output_sink);
  swap(a.partition, b.partition);
  swap(a.__isset, b.__isset);
}

TPlanFragment::TPlanFragment(const TPlanFragment& other6) {
  plan = other6.plan;
  output_exprs = other6.output_exprs;
  output_sink = other6.output_sink;
  partition = other6.partition;
  __isset = other6.__isset;
}
TPlanFragment& TPlanFragment::operator=(const TPlanFragment& other7) {
  plan = other7.plan;
  output_exprs = other7.output_exprs;
  output_sink = other7.output_sink;
  partition = other7.partition;
  __isset = other7.__isset;
  return *this;
}
void TPlanFragment::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPlanFragment(";
  out << "plan="; (__isset.plan ? (out << to_string(plan)) : (out << "<null>"));
  out << ", " << "output_exprs="; (__isset.output_exprs ? (out << to_string(output_exprs)) : (out << "<null>"));
  out << ", " << "output_sink="; (__isset.output_sink ? (out << to_string(output_sink)) : (out << "<null>"));
  out << ", " << "partition=" << to_string(partition);
  out << ")";
}


TScanRangeLocation::~TScanRangeLocation() throw() {
}


void TScanRangeLocation::__set_server(const  ::palo::TNetworkAddress& val) {
  this->server = val;
}

void TScanRangeLocation::__set_volume_id(const int32_t val) {
  this->volume_id = val;
__isset.volume_id = true;
}

void TScanRangeLocation::__set_backend_id(const int64_t val) {
  this->backend_id = val;
__isset.backend_id = true;
}

uint32_t TScanRangeLocation::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_server = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->server.read(iprot);
          isset_server = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->volume_id);
          this->__isset.volume_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->backend_id);
          this->__isset.backend_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_server)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TScanRangeLocation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TScanRangeLocation");

  xfer += oprot->writeFieldBegin("server", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->server.write(oprot);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.volume_id) {
    xfer += oprot->writeFieldBegin("volume_id", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->volume_id);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.backend_id) {
    xfer += oprot->writeFieldBegin("backend_id", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->backend_id);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TScanRangeLocation &a, TScanRangeLocation &b) {
  using ::std::swap;
  swap(a.server, b.server);
  swap(a.volume_id, b.volume_id);
  swap(a.backend_id, b.backend_id);
  swap(a.__isset, b.__isset);
}

TScanRangeLocation::TScanRangeLocation(const TScanRangeLocation& other8) {
  server = other8.server;
  volume_id = other8.volume_id;
  backend_id = other8.backend_id;
  __isset = other8.__isset;
}
TScanRangeLocation& TScanRangeLocation::operator=(const TScanRangeLocation& other9) {
  server = other9.server;
  volume_id = other9.volume_id;
  backend_id = other9.backend_id;
  __isset = other9.__isset;
  return *this;
}
void TScanRangeLocation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TScanRangeLocation(";
  out << "server=" << to_string(server);
  out << ", " << "volume_id="; (__isset.volume_id ? (out << to_string(volume_id)) : (out << "<null>"));
  out << ", " << "backend_id="; (__isset.backend_id ? (out << to_string(backend_id)) : (out << "<null>"));
  out << ")";
}


TScanRangeLocations::~TScanRangeLocations() throw() {
}


void TScanRangeLocations::__set_scan_range(const  ::palo::TScanRange& val) {
  this->scan_range = val;
}

void TScanRangeLocations::__set_locations(const std::vector<TScanRangeLocation> & val) {
  this->locations = val;
}

uint32_t TScanRangeLocations::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_scan_range = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->scan_range.read(iprot);
          isset_scan_range = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->locations.clear();
            uint32_t _size10;
            ::apache::thrift::protocol::TType _etype13;
            xfer += iprot->readListBegin(_etype13, _size10);
            this->locations.resize(_size10);
            uint32_t _i14;
            for (_i14 = 0; _i14 < _size10; ++_i14)
            {
              xfer += this->locations[_i14].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.locations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_scan_range)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TScanRangeLocations::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TScanRangeLocations");

  xfer += oprot->writeFieldBegin("scan_range", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->scan_range.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("locations", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->locations.size()));
    std::vector<TScanRangeLocation> ::const_iterator _iter15;
    for (_iter15 = this->locations.begin(); _iter15 != this->locations.end(); ++_iter15)
    {
      xfer += (*_iter15).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TScanRangeLocations &a, TScanRangeLocations &b) {
  using ::std::swap;
  swap(a.scan_range, b.scan_range);
  swap(a.locations, b.locations);
  swap(a.__isset, b.__isset);
}

TScanRangeLocations::TScanRangeLocations(const TScanRangeLocations& other16) {
  scan_range = other16.scan_range;
  locations = other16.locations;
  __isset = other16.__isset;
}
TScanRangeLocations& TScanRangeLocations::operator=(const TScanRangeLocations& other17) {
  scan_range = other17.scan_range;
  locations = other17.locations;
  __isset = other17.__isset;
  return *this;
}
void TScanRangeLocations::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TScanRangeLocations(";
  out << "scan_range=" << to_string(scan_range);
  out << ", " << "locations=" << to_string(locations);
  out << ")";
}

} // namespace