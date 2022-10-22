#include <iostream>

namespace cdps {
class singleton {
 public:
  std::string desc;

  // making constructor not working, same effect as making constructor private
  singleton(singleton const&) = delete;
  // making assignment operator not working
  singleton& operator=(singleton const&) = delete;

  static singleton* get() {
    if (!instance) {
      instance = new singleton();
      instance->desc = "singleton";
    }

    return instance;
  }

 private:
  singleton() {
  }
  static singleton* instance;
};
}  // namespace cdps

cdps::singleton* cdps::singleton::instance = nullptr;
