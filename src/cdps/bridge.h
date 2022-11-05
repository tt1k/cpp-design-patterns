#include <iostream>

namespace cdps {
class implementor {
 public:
  virtual void operation_impl() = 0;
};
class concrete_implementor_a : public implementor {
 public:
  void operation_impl() override {
    std::cout << "[IMPL]: Concreate A" << std::endl;
  }
};
class concrete_implementor_b : public implementor {
 public:
  void operation_impl() override {
    std::cout << "[IMPL]: Concreate B" << std::endl;
  }
};
class abstraction {
 public:
  virtual void operation() = 0;
};
class refined_abstraction : public abstraction {
 public:
  refined_abstraction(cdps::implementor* i) {
    impl = i;
  }
  void operation() {
    impl->operation_impl();
  }

 private:
  cdps::implementor* impl;
};
}  // namespace cdps
