#include <iostream>

namespace cdps {
class service {
 public:
  void operation() {
    std::cout << "[PROXY]: Service started" << std::endl;
  }
};
class proxy {
 public:
  proxy() {
    real_service = new cdps::service();
  }
  void operation() {
    real_service->operation();
  }

 private:
  cdps::service* real_service;
};
}  // namespace cdps
