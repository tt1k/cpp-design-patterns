#include <iostream>
#include <vector>

namespace cdps {
class receiver {
 public:
  receiver() {
    num = 100;
  }
  void excute_with_param(int i) {
    num += i;
    std::cout << "receiver make request with " << i << ": after num is " << num << std::endl;
  }

 private:
  int num;
};

class command {
 public:
  virtual void confirm() = 0;
};

class add_command : public command {
 public:
  add_command(cdps::receiver* r) {
    receiver = r;
  }
  void confirm() override {
    receiver->excute_with_param(1);
  }

 private:
  cdps::receiver* receiver;
};

class sub_command : public command {
 public:
  sub_command(cdps::receiver* r) {
    receiver = r;
  }
  void confirm() override {
    receiver->excute_with_param(-1);
  }

 private:
  cdps::receiver* receiver;
};

class invoker {
 public:
  void set_command(cdps::command* c) {
    commands.push_back(c);
  }
  void comfirm_command() {
    for (auto& c : commands) {
      c->confirm();
    }

    commands.clear();
  }

 private:
  std::vector<cdps::command*> commands;
};
}  // namespace cdps
