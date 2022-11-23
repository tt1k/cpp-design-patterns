#include <iostream>

namespace cdps {
class state_context;

class state {
 public:
  virtual std::string description() = 0;
  virtual void do_action(cdps::state_context* context) = 0;
};

class state_context {
 public:
  void set_state(cdps::state* s) {
    state = s;
  }
  std::string description() {
    return "current state: " + state->description();
  }

 private:
  cdps::state* state;
};

class active_state : public state {
 public:
  std::string description() override {
    return "active state";
  }
  void do_action(cdps::state_context* context) override {
    std::cout << "do action: now active state" << std::endl;
    context->set_state(this);
  }
};

class inactive_state : public state {
 public:
  std::string description() override {
    return "inactive state";
  }
  void do_action(cdps::state_context* context) override {
    std::cout << "do action: now inactive state" << std::endl;
    context->set_state(this);
  }
};
}  // namespace cdps
