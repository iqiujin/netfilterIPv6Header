/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RecvCommand_H
#define RecvCommand_H

#include <thrift/TDispatchProcessor.h>
#include "ip_rule_types.h"



class RecvCommandIf {
 public:
  virtual ~RecvCommandIf() {}
  virtual bool add_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port) = 0;
  virtual bool del_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port) = 0;
  virtual int32_t is_alive() = 0;
};

class RecvCommandIfFactory {
 public:
  typedef RecvCommandIf Handler;

  virtual ~RecvCommandIfFactory() {}

  virtual RecvCommandIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RecvCommandIf* /* handler */) = 0;
};

class RecvCommandIfSingletonFactory : virtual public RecvCommandIfFactory {
 public:
  RecvCommandIfSingletonFactory(const boost::shared_ptr<RecvCommandIf>& iface) : iface_(iface) {}
  virtual ~RecvCommandIfSingletonFactory() {}

  virtual RecvCommandIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RecvCommandIf* /* handler */) {}

 protected:
  boost::shared_ptr<RecvCommandIf> iface_;
};

class RecvCommandNull : virtual public RecvCommandIf {
 public:
  virtual ~RecvCommandNull() {}
  bool add_measure_group(const std::string& /* str_addr */, const int32_t /* interval */, const int32_t /* port */) {
    bool _return = false;
    return _return;
  }
  bool del_measure_group(const std::string& /* str_addr */, const int32_t /* interval */, const int32_t /* port */) {
    bool _return = false;
    return _return;
  }
  int32_t is_alive() {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _RecvCommand_add_measure_group_args__isset {
  _RecvCommand_add_measure_group_args__isset() : str_addr(false), interval(false), port(false) {}
  bool str_addr;
  bool interval;
  bool port;
} _RecvCommand_add_measure_group_args__isset;

class RecvCommand_add_measure_group_args {
 public:

  RecvCommand_add_measure_group_args() : str_addr(), interval(0), port(0) {
  }

  virtual ~RecvCommand_add_measure_group_args() throw() {}

  std::string str_addr;
  int32_t interval;
  int32_t port;

  _RecvCommand_add_measure_group_args__isset __isset;

  void __set_str_addr(const std::string& val) {
    str_addr = val;
  }

  void __set_interval(const int32_t val) {
    interval = val;
  }

  void __set_port(const int32_t val) {
    port = val;
  }

  bool operator == (const RecvCommand_add_measure_group_args & rhs) const
  {
    if (!(str_addr == rhs.str_addr))
      return false;
    if (!(interval == rhs.interval))
      return false;
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const RecvCommand_add_measure_group_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_add_measure_group_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RecvCommand_add_measure_group_pargs {
 public:


  virtual ~RecvCommand_add_measure_group_pargs() throw() {}

  const std::string* str_addr;
  const int32_t* interval;
  const int32_t* port;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_add_measure_group_result__isset {
  _RecvCommand_add_measure_group_result__isset() : success(false) {}
  bool success;
} _RecvCommand_add_measure_group_result__isset;

class RecvCommand_add_measure_group_result {
 public:

  RecvCommand_add_measure_group_result() : success(0) {
  }

  virtual ~RecvCommand_add_measure_group_result() throw() {}

  bool success;

  _RecvCommand_add_measure_group_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const RecvCommand_add_measure_group_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RecvCommand_add_measure_group_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_add_measure_group_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_add_measure_group_presult__isset {
  _RecvCommand_add_measure_group_presult__isset() : success(false) {}
  bool success;
} _RecvCommand_add_measure_group_presult__isset;

class RecvCommand_add_measure_group_presult {
 public:


  virtual ~RecvCommand_add_measure_group_presult() throw() {}

  bool* success;

  _RecvCommand_add_measure_group_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RecvCommand_del_measure_group_args__isset {
  _RecvCommand_del_measure_group_args__isset() : str_addr(false), interval(false), port(false) {}
  bool str_addr;
  bool interval;
  bool port;
} _RecvCommand_del_measure_group_args__isset;

class RecvCommand_del_measure_group_args {
 public:

  RecvCommand_del_measure_group_args() : str_addr(), interval(0), port(0) {
  }

  virtual ~RecvCommand_del_measure_group_args() throw() {}

  std::string str_addr;
  int32_t interval;
  int32_t port;

  _RecvCommand_del_measure_group_args__isset __isset;

  void __set_str_addr(const std::string& val) {
    str_addr = val;
  }

  void __set_interval(const int32_t val) {
    interval = val;
  }

  void __set_port(const int32_t val) {
    port = val;
  }

  bool operator == (const RecvCommand_del_measure_group_args & rhs) const
  {
    if (!(str_addr == rhs.str_addr))
      return false;
    if (!(interval == rhs.interval))
      return false;
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const RecvCommand_del_measure_group_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_del_measure_group_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RecvCommand_del_measure_group_pargs {
 public:


  virtual ~RecvCommand_del_measure_group_pargs() throw() {}

  const std::string* str_addr;
  const int32_t* interval;
  const int32_t* port;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_del_measure_group_result__isset {
  _RecvCommand_del_measure_group_result__isset() : success(false) {}
  bool success;
} _RecvCommand_del_measure_group_result__isset;

class RecvCommand_del_measure_group_result {
 public:

  RecvCommand_del_measure_group_result() : success(0) {
  }

  virtual ~RecvCommand_del_measure_group_result() throw() {}

  bool success;

  _RecvCommand_del_measure_group_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const RecvCommand_del_measure_group_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RecvCommand_del_measure_group_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_del_measure_group_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_del_measure_group_presult__isset {
  _RecvCommand_del_measure_group_presult__isset() : success(false) {}
  bool success;
} _RecvCommand_del_measure_group_presult__isset;

class RecvCommand_del_measure_group_presult {
 public:


  virtual ~RecvCommand_del_measure_group_presult() throw() {}

  bool* success;

  _RecvCommand_del_measure_group_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class RecvCommand_is_alive_args {
 public:

  RecvCommand_is_alive_args() {
  }

  virtual ~RecvCommand_is_alive_args() throw() {}


  bool operator == (const RecvCommand_is_alive_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RecvCommand_is_alive_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_is_alive_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RecvCommand_is_alive_pargs {
 public:


  virtual ~RecvCommand_is_alive_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_is_alive_result__isset {
  _RecvCommand_is_alive_result__isset() : success(false) {}
  bool success;
} _RecvCommand_is_alive_result__isset;

class RecvCommand_is_alive_result {
 public:

  RecvCommand_is_alive_result() : success(0) {
  }

  virtual ~RecvCommand_is_alive_result() throw() {}

  int32_t success;

  _RecvCommand_is_alive_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const RecvCommand_is_alive_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RecvCommand_is_alive_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RecvCommand_is_alive_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RecvCommand_is_alive_presult__isset {
  _RecvCommand_is_alive_presult__isset() : success(false) {}
  bool success;
} _RecvCommand_is_alive_presult__isset;

class RecvCommand_is_alive_presult {
 public:


  virtual ~RecvCommand_is_alive_presult() throw() {}

  int32_t* success;

  _RecvCommand_is_alive_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RecvCommandClient : virtual public RecvCommandIf {
 public:
  RecvCommandClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  RecvCommandClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool add_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port);
  void send_add_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port);
  bool recv_add_measure_group();
  bool del_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port);
  void send_del_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port);
  bool recv_del_measure_group();
  int32_t is_alive();
  void send_is_alive();
  int32_t recv_is_alive();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RecvCommandProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<RecvCommandIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RecvCommandProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_add_measure_group(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_del_measure_group(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_is_alive(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RecvCommandProcessor(boost::shared_ptr<RecvCommandIf> iface) :
    iface_(iface) {
    processMap_["add_measure_group"] = &RecvCommandProcessor::process_add_measure_group;
    processMap_["del_measure_group"] = &RecvCommandProcessor::process_del_measure_group;
    processMap_["is_alive"] = &RecvCommandProcessor::process_is_alive;
  }

  virtual ~RecvCommandProcessor() {}
};

class RecvCommandProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RecvCommandProcessorFactory(const ::boost::shared_ptr< RecvCommandIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RecvCommandIfFactory > handlerFactory_;
};

class RecvCommandMultiface : virtual public RecvCommandIf {
 public:
  RecvCommandMultiface(std::vector<boost::shared_ptr<RecvCommandIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RecvCommandMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RecvCommandIf> > ifaces_;
  RecvCommandMultiface() {}
  void add(boost::shared_ptr<RecvCommandIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool add_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->add_measure_group(str_addr, interval, port);
    }
    return ifaces_[i]->add_measure_group(str_addr, interval, port);
  }

  bool del_measure_group(const std::string& str_addr, const int32_t interval, const int32_t port) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->del_measure_group(str_addr, interval, port);
    }
    return ifaces_[i]->del_measure_group(str_addr, interval, port);
  }

  int32_t is_alive() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->is_alive();
    }
    return ifaces_[i]->is_alive();
  }

};



#endif