#include "server/common/net/socket.h"

namespace pap_server_common_net {

Socket::Socket(uint16_t port, uint32_t backlog) {
  __ENTER_FUNCTION
    bool result = false;
    socket_ = new pap_common_net::socket::Base;
    NULL == socket_ && throw 1;
    result = socket_->create();
    false == result && throw 1;
    result = socket_->set_reuseaddr();
    false == result && throw 1;
    result = socket_->bind(port);
    false == result && throw 1;
    result = socket_->listen(backlog);
    false == result && throw 1;
  __LEAVE_FUNCTION
}

Socket::~Socket() {
  __ENTER_FUNCTION
    if (socket_ != NULL) {
      socket_->close();
      SAFE_DELETE(socket_);
    }
  __LEAVE_FUNCTION
}

void Socket::close() {
  socket_ != NULL && socket_->close();
}

bool Socket::accept(pap_common_net::socket::Base* socket) {
  __ENTER_FUNCTION
    if (NULL == socket) return false;
    int32_t result = SOCKET_INVALID;
    socket->close();
    if (0 == socket->port_) {
      result = socket->fastaccept();
    }
    else {
      result = socket->accept(socket->port_);
    }
    SOCKET_INVALID == result && return false;
    return true;
  __LEAVE_FUNCTION
    return false;
}

uint32_t Socket::getlinger() const {
  __ENTER_FUNCTION
    uint32_t linger;
    linger = socket_->getlinger();
    return linger;
  __LEAVE_FUNCTION
    return 0;
}

bool Socket::setlinger(uint32_t lingertime) {
  __ENTER_FUNCTION
    bool result = false;
    result = socket_->setlinger(lingertime);
    return result;
  __LEAVE_FUNCTION
    return false;
}

bool Socket::is_nonblocking() const {
  __ENTER_FUNCTION
    bool result = false;
    result = socket_->is_nonblocking();
    return result;
  __LEAVE_FUNCTION
    return false;
}

void Socket::set_nonblocking(bool on) {
  __ENTER_FUNCTION
    socket_->set_nonblocking(on);
  __LEAVE_FUNCTION
}

uint32_t Socket::getreceive_buffersize() const {
  __ENTER_FUNCTION
    uint32_t result = 0;
    result = socket_->getreceive_buffersize();
    return result;
  __LEAVE_FUNCTION
    return 0;
}

bool Socket::setreceive_buffersize(uint32_t size) {
  __ENTER_FUNCTION
    bool result = false;
    result = socket_->setreceive_buffersize(size);
    return result;
  __LEAVE_FUNCTION
    return false;
}

} //namespace pap_server_common_net
