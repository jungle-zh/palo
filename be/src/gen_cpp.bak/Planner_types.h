/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Planner_TYPES_H
#define Planner_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Types_types.h"
#include "Exprs_types.h"
#include "DataSinks_types.h"
#include "PlanNodes_types.h"
#include "Partitions_types.h"


namespace palo {

class TPlanFragment;

class TScanRangeLocation;

class TScanRangeLocations;

typedef struct _TPlanFragment__isset {
  _TPlanFragment__isset() : plan(false), output_exprs(false), output_sink(false) {}
  bool plan :1;
  bool output_exprs :1;
  bool output_sink :1;
} _TPlanFragment__isset;

class TPlanFragment {
 public:

  TPlanFragment(const TPlanFragment&);
  TPlanFragment& operator=(const TPlanFragment&);
  TPlanFragment() {
  }

  virtual ~TPlanFragment() throw();
   ::palo::TPlan plan;
  std::vector< ::palo::TExpr>  output_exprs;
   ::palo::TDataSink output_sink;
   ::palo::TDataPartition partition;

  _TPlanFragment__isset __isset;

  void __set_plan(const  ::palo::TPlan& val);

  void __set_output_exprs(const std::vector< ::palo::TExpr> & val);

  void __set_output_sink(const  ::palo::TDataSink& val);

  void __set_partition(const  ::palo::TDataPartition& val);

  bool operator == (const TPlanFragment & rhs) const
  {
    if (__isset.plan != rhs.__isset.plan)
      return false;
    else if (__isset.plan && !(plan == rhs.plan))
      return false;
    if (__isset.output_exprs != rhs.__isset.output_exprs)
      return false;
    else if (__isset.output_exprs && !(output_exprs == rhs.output_exprs))
      return false;
    if (__isset.output_sink != rhs.__isset.output_sink)
      return false;
    else if (__isset.output_sink && !(output_sink == rhs.output_sink))
      return false;
    if (!(partition == rhs.partition))
      return false;
    return true;
  }
  bool operator != (const TPlanFragment &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TPlanFragment & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPlanFragment &a, TPlanFragment &b);

inline std::ostream& operator<<(std::ostream& out, const TPlanFragment& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TScanRangeLocation__isset {
  _TScanRangeLocation__isset() : volume_id(true), backend_id(false) {}
  bool volume_id :1;
  bool backend_id :1;
} _TScanRangeLocation__isset;

class TScanRangeLocation {
 public:

  TScanRangeLocation(const TScanRangeLocation&);
  TScanRangeLocation& operator=(const TScanRangeLocation&);
  TScanRangeLocation() : volume_id(-1), backend_id(0) {
  }

  virtual ~TScanRangeLocation() throw();
   ::palo::TNetworkAddress server;
  int32_t volume_id;
  int64_t backend_id;

  _TScanRangeLocation__isset __isset;

  void __set_server(const  ::palo::TNetworkAddress& val);

  void __set_volume_id(const int32_t val);

  void __set_backend_id(const int64_t val);

  bool operator == (const TScanRangeLocation & rhs) const
  {
    if (!(server == rhs.server))
      return false;
    if (__isset.volume_id != rhs.__isset.volume_id)
      return false;
    else if (__isset.volume_id && !(volume_id == rhs.volume_id))
      return false;
    if (__isset.backend_id != rhs.__isset.backend_id)
      return false;
    else if (__isset.backend_id && !(backend_id == rhs.backend_id))
      return false;
    return true;
  }
  bool operator != (const TScanRangeLocation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TScanRangeLocation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TScanRangeLocation &a, TScanRangeLocation &b);

inline std::ostream& operator<<(std::ostream& out, const TScanRangeLocation& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _TScanRangeLocations__isset {
  _TScanRangeLocations__isset() : locations(false) {}
  bool locations :1;
} _TScanRangeLocations__isset;

class TScanRangeLocations {
 public:

  TScanRangeLocations(const TScanRangeLocations&);
  TScanRangeLocations& operator=(const TScanRangeLocations&);
  TScanRangeLocations() {
  }

  virtual ~TScanRangeLocations() throw();
   ::palo::TScanRange scan_range;
  std::vector<TScanRangeLocation>  locations;

  _TScanRangeLocations__isset __isset;

  void __set_scan_range(const  ::palo::TScanRange& val);

  void __set_locations(const std::vector<TScanRangeLocation> & val);

  bool operator == (const TScanRangeLocations & rhs) const
  {
    if (!(scan_range == rhs.scan_range))
      return false;
    if (!(locations == rhs.locations))
      return false;
    return true;
  }
  bool operator != (const TScanRangeLocations &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TScanRangeLocations & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TScanRangeLocations &a, TScanRangeLocations &b);

inline std::ostream& operator<<(std::ostream& out, const TScanRangeLocations& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif