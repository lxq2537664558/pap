/**
 * PAP Engine ( https://github.com/viticm/pap )
 * $Id socket.h
 * @link https://github.com/viticm/pap for the canonical source repository
 * @copyright Copyright (c) 2013-2013 viticm( viticm@126.com )
 * @license
 * @user viticm<viticm@126.com>
 * @date 2013-12-31 17:34:43
 * @uses server and client net model socket class
 */
#ifndef PAP_COMMON_NET_SOCKET_H_
#define PAP_COMMON_NET_SOCKET_H_

#include "common/net/config.h"

namespace pap_common_net {

class Socket {
 
 public:
   Socket();
   Socket(const char* host, uint16_t port);
   virtual ~Socket();

 public:
   int32_t socketid_;
   char host_[IP_SIZE];
   uint16_t port_;

 public: //socket base operate functions
   bool create();
   void close();
   bool connect(); //use self host_ and port_
   bool connect(const char* host, uint16_t port);
   bool reconnect(const char* host, uint16_t port);
   uint32_t send(const void* buffer, uint32_t length, uint32_t flag = 0);
   uint32_t receive(void* buffer, uint32_t length, uint32_t flag = 0);
   uint32_t available() const;
   int32_t accept(uint16_t port);
   int32_t fastaccept();
   bool bind();
   bool bind(uint16_t port);
   bool listen(uint32_t backlog);
 
 public: //socket check and set functions
   uint32_t getlinger() const;
   bool setlinger(uint32_t lingertime);
   bool is_reuseaddr() const;
   bool set_reuseaddr(bool on = true);
   uint32_t getlast_errorcode() const;
   void getlast_errormessage(char* buffer, uint16_t length) const;
   bool iserror() const; //socket if has error
   bool is_nonblocking() const;
   bool set_nonblocking(bool on = true);
   uint32_t getreceive_buffersize() const;
   bool setreceive_buffersize(uint32_t size);
   uint32_t getsend_buffersize() const;
   bool setsend_buffersize(uint32_t size);
   uint16_t getport() const;
   uint64_t getu64host() const;
   bool isvalid() const;
   int32_t getid() const;

};

}; //namespace pap_common_net

#endif //PAP_COMMON_NET_SOCKET_H_
