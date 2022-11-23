#include <iostream>

namespace cdps {
class strategy_op {
 public:
  virtual int excute_strategy(int a, int b) = 0;
};

class strategy_context {
 public:
  strategy_context(cdps::strategy_op* o) {
    op = o;
  }
  void excute(int a, int b) {
    std::cout << "excute: " << op->excute_strategy(a, b) << std::endl;
  }

 private:
  cdps::strategy_op* op;
};

class strategy_op_add : public strategy_op {
 public:
  int excute_strategy(int a, int b) override {
    return a + b;
  }
};

class strategy_op_sub : public strategy_op {
 public:
  int excute_strategy(int a, int b) override {
    return a - b;
  }
};

}  // namespace cdps
