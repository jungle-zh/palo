/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RuntimeProfile_TYPES_H
#define RuntimeProfile_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "Metrics_types.h"


namespace palo {

class TCounter;

class TRuntimeProfileNode;

class TRuntimeProfileTree;


class TCounter {
 public:

  TCounter(const TCounter&);
  TCounter& operator=(const TCounter&);
  TCounter() : name(), type(( ::palo::TUnit::type)0), value(0) {
  }

  virtual ~TCounter() throw();
  std::string name;
   ::palo::TUnit::type type;
  int64_t value;

  void __set_name(const std::string& val);

  void __set_type(const  ::palo::TUnit::type val);

  void __set_value(const int64_t val);

  bool operator == (const TCounter & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(type == rhs.type))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const TCounter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TCounter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCounter &a, TCounter &b);

inline std::ostream& operator<<(std::ostream& out, const TCounter& obj)
{
  obj.printTo(out);
  return out;
}


class TRuntimeProfileNode {
 public:

  TRuntimeProfileNode(const TRuntimeProfileNode&);
  TRuntimeProfileNode& operator=(const TRuntimeProfileNode&);
  TRuntimeProfileNode() : name(), num_children(0), metadata(0), indent(0) {
  }

  virtual ~TRuntimeProfileNode() throw();
  std::string name;
  int32_t num_children;
  std::vector<TCounter>  counters;
  int64_t metadata;
  bool indent;
  std::map<std::string, std::string>  info_strings;
  std::vector<std::string>  info_strings_display_order;
  std::map<std::string, std::set<std::string> >  child_counters_map;

  void __set_name(const std::string& val);

  void __set_num_children(const int32_t val);

  void __set_counters(const std::vector<TCounter> & val);

  void __set_metadata(const int64_t val);

  void __set_indent(const bool val);

  void __set_info_strings(const std::map<std::string, std::string> & val);

  void __set_info_strings_display_order(const std::vector<std::string> & val);

  void __set_child_counters_map(const std::map<std::string, std::set<std::string> > & val);

  bool operator == (const TRuntimeProfileNode & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(num_children == rhs.num_children))
      return false;
    if (!(counters == rhs.counters))
      return false;
    if (!(metadata == rhs.metadata))
      return false;
    if (!(indent == rhs.indent))
      return false;
    if (!(info_strings == rhs.info_strings))
      return false;
    if (!(info_strings_display_order == rhs.info_strings_display_order))
      return false;
    if (!(child_counters_map == rhs.child_counters_map))
      return false;
    return true;
  }
  bool operator != (const TRuntimeProfileNode &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRuntimeProfileNode & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRuntimeProfileNode &a, TRuntimeProfileNode &b);

inline std::ostream& operator<<(std::ostream& out, const TRuntimeProfileNode& obj)
{
  obj.printTo(out);
  return out;
}


class TRuntimeProfileTree {
 public:

  TRuntimeProfileTree(const TRuntimeProfileTree&);
  TRuntimeProfileTree& operator=(const TRuntimeProfileTree&);
  TRuntimeProfileTree() {
  }

  virtual ~TRuntimeProfileTree() throw();
  std::vector<TRuntimeProfileNode>  nodes;

  void __set_nodes(const std::vector<TRuntimeProfileNode> & val);

  bool operator == (const TRuntimeProfileTree & rhs) const
  {
    if (!(nodes == rhs.nodes))
      return false;
    return true;
  }
  bool operator != (const TRuntimeProfileTree &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TRuntimeProfileTree & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRuntimeProfileTree &a, TRuntimeProfileTree &b);

inline std::ostream& operator<<(std::ostream& out, const TRuntimeProfileTree& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif