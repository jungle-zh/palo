/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef NetworkTestService_H
#define NetworkTestService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "NetworkTest_types.h"

namespace palotest {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class NetworkTestServiceIf {
 public:
  virtual ~NetworkTestServiceIf() {}
  virtual void Send(ThriftDataResult& _return, const ThriftDataParams& params) = 0;
};

class NetworkTestServiceIfFactory {
 public:
  typedef NetworkTestServiceIf Handler;

  virtual ~NetworkTestServiceIfFactory() {}

  virtual NetworkTestServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(NetworkTestServiceIf* /* handler */) = 0;
};

class NetworkTestServiceIfSingletonFactory : virtual public NetworkTestServiceIfFactory {
 public:
  NetworkTestServiceIfSingletonFactory(const boost::shared_ptr<NetworkTestServiceIf>& iface) : iface_(iface) {}
  virtual ~NetworkTestServiceIfSingletonFactory() {}

  virtual NetworkTestServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(NetworkTestServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<NetworkTestServiceIf> iface_;
};

class NetworkTestServiceNull : virtual public NetworkTestServiceIf {
 public:
  virtual ~NetworkTestServiceNull() {}
  void Send(ThriftDataResult& /* _return */, const ThriftDataParams& /* params */) {
    return;
  }
};

typedef struct _NetworkTestService_Send_args__isset {
  _NetworkTestService_Send_args__isset() : params(false) {}
  bool params :1;
} _NetworkTestService_Send_args__isset;

class NetworkTestService_Send_args {
 public:

  NetworkTestService_Send_args(const NetworkTestService_Send_args&);
  NetworkTestService_Send_args& operator=(const NetworkTestService_Send_args&);
  NetworkTestService_Send_args() {
  }

  virtual ~NetworkTestService_Send_args() throw();
  ThriftDataParams params;

  _NetworkTestService_Send_args__isset __isset;

  void __set_params(const ThriftDataParams& val);

  bool operator == (const NetworkTestService_Send_args & rhs) const
  {
    if (!(params == rhs.params))
      return false;
    return true;
  }
  bool operator != (const NetworkTestService_Send_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NetworkTestService_Send_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class NetworkTestService_Send_pargs {
 public:


  virtual ~NetworkTestService_Send_pargs() throw();
  const ThriftDataParams* params;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NetworkTestService_Send_result__isset {
  _NetworkTestService_Send_result__isset() : success(false) {}
  bool success :1;
} _NetworkTestService_Send_result__isset;

class NetworkTestService_Send_result {
 public:

  NetworkTestService_Send_result(const NetworkTestService_Send_result&);
  NetworkTestService_Send_result& operator=(const NetworkTestService_Send_result&);
  NetworkTestService_Send_result() {
  }

  virtual ~NetworkTestService_Send_result() throw();
  ThriftDataResult success;

  _NetworkTestService_Send_result__isset __isset;

  void __set_success(const ThriftDataResult& val);

  bool operator == (const NetworkTestService_Send_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const NetworkTestService_Send_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NetworkTestService_Send_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _NetworkTestService_Send_presult__isset {
  _NetworkTestService_Send_presult__isset() : success(false) {}
  bool success :1;
} _NetworkTestService_Send_presult__isset;

class NetworkTestService_Send_presult {
 public:


  virtual ~NetworkTestService_Send_presult() throw();
  ThriftDataResult* success;

  _NetworkTestService_Send_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class NetworkTestServiceClient : virtual public NetworkTestServiceIf {
 public:
  NetworkTestServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NetworkTestServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Send(ThriftDataResult& _return, const ThriftDataParams& params);
  void send_Send(const ThriftDataParams& params);
  void recv_Send(ThriftDataResult& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class NetworkTestServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<NetworkTestServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (NetworkTestServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Send(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  NetworkTestServiceProcessor(boost::shared_ptr<NetworkTestServiceIf> iface) :
    iface_(iface) {
    processMap_["Send"] = &NetworkTestServiceProcessor::process_Send;
  }

  virtual ~NetworkTestServiceProcessor() {}
};

class NetworkTestServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  NetworkTestServiceProcessorFactory(const ::boost::shared_ptr< NetworkTestServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< NetworkTestServiceIfFactory > handlerFactory_;
};

class NetworkTestServiceMultiface : virtual public NetworkTestServiceIf {
 public:
  NetworkTestServiceMultiface(std::vector<boost::shared_ptr<NetworkTestServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~NetworkTestServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<NetworkTestServiceIf> > ifaces_;
  NetworkTestServiceMultiface() {}
  void add(boost::shared_ptr<NetworkTestServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void Send(ThriftDataResult& _return, const ThriftDataParams& params) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Send(_return, params);
    }
    ifaces_[i]->Send(_return, params);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class NetworkTestServiceConcurrentClient : virtual public NetworkTestServiceIf {
 public:
  NetworkTestServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  NetworkTestServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Send(ThriftDataResult& _return, const ThriftDataParams& params);
  int32_t send_Send(const ThriftDataParams& params);
  void recv_Send(ThriftDataResult& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif