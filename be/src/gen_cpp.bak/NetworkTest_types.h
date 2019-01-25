/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef NetworkTest_TYPES_H
#define NetworkTest_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace palotest {

class ThriftDataParams;

class ThriftDataResult;


class ThriftDataParams {
 public:

  ThriftDataParams(const ThriftDataParams&);
  ThriftDataParams& operator=(const ThriftDataParams&);
  ThriftDataParams() : data() {
  }

  virtual ~ThriftDataParams() throw();
  std::string data;

  void __set_data(const std::string& val);

  bool operator == (const ThriftDataParams & rhs) const
  {
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const ThriftDataParams &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftDataParams & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftDataParams &a, ThriftDataParams &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftDataParams& obj)
{
  obj.printTo(out);
  return out;
}


class ThriftDataResult {
 public:

  ThriftDataResult(const ThriftDataResult&);
  ThriftDataResult& operator=(const ThriftDataResult&);
  ThriftDataResult() : bytes_received(0) {
  }

  virtual ~ThriftDataResult() throw();
  int64_t bytes_received;

  void __set_bytes_received(const int64_t val);

  bool operator == (const ThriftDataResult & rhs) const
  {
    if (!(bytes_received == rhs.bytes_received))
      return false;
    return true;
  }
  bool operator != (const ThriftDataResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftDataResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ThriftDataResult &a, ThriftDataResult &b);

inline std::ostream& operator<<(std::ostream& out, const ThriftDataResult& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
