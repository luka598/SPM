#include "error.hpp"
#include <iostream>
#include <type_traits>

#ifdef ERROR_FATAL
#include <stdexcept>
#endif

namespace lang {
Error::Error(){};

std::string Error::message() const { return ss.str(); }

Error::operator bool() const { return thrown; }

Error &operator<<(Error &obj, const END &_) {
#ifdef ERROR_FATAL
  if (obj.thrown) {
    throw std::runtime_error(obj.message());
  }
#endif
  return obj;
}

Error &operator<<(Error &obj, const Error &e) {
  if (e.thrown)
    obj << "Err from: " << __PRETTY_FUNCTION__ << e.message();
  return obj;
}

std::ostream &operator<<(std::ostream &os, const Error &obj) {
  if (obj.thrown) {
    os << "!(" << obj.message() << ")";
  }
  return os;
}

} // namespace lang