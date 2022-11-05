#include <iostream>

namespace cdps {
class prototype {
 public:
  virtual cdps::prototype* clone() = 0;
  virtual std::string type() = 0;
};
class concrete_prototype_a : public prototype {
 public:
  cdps::prototype* clone() override {
    std::cout << "[PROTOTYPE]: clone a" << std::endl;
    return new cdps::concrete_prototype_a();
  }
  std::string type() override {
    return "type a";
  }
};
class concrete_prototype_b : public prototype {
 public:
  cdps::prototype* clone() override {
    std::cout << "[PROTOTYPE]: clone b" << std::endl;
    return new cdps::concrete_prototype_b();
  }
  std::string type() override {
    return "type b";
  }
};
class prototype_client {
 public:
  static void init() {
    types[0] = new cdps::concrete_prototype_a();
    types[1] = new cdps::concrete_prototype_b();
  }
  static cdps::prototype* make(int type) {
    if (type > types_count) {
      return nullptr;
    }
    return types[type]->clone();
  }

 private:
  static cdps::prototype* types[2];
  static int types_count;
};
}  // namespace cdps
