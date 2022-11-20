#include <iostream>

namespace cdps {
class class_target {
 public:
  virtual void request() = 0;
};

class class_adaptee {
 public:
  void real_request() {
    std::cout << "real request from class adaptee" << std::endl;
  }
};

class class_adapter : public class_target, private class_adaptee {
 public:
  void request() override {
    real_request();
  }
};

class object_target {
 public:
  virtual void request() = 0;
};

class object_adaptee {
 public:
  void real_request() {
    std::cout << "real request from object adaptee" << std::endl;
  }
};

class object_adapter : public object_target, private object_adaptee {
 public:
  object_adapter() {
    adaptee = new cdps::object_adaptee();
  }
  void request() override {
    adaptee->real_request();
  }

 private:
  cdps::object_adaptee* adaptee;
};
}  // namespace cdps
