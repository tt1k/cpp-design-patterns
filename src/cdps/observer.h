#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>

namespace cdps {
class subject;
class observer {
 public:
  cdps::subject* sub;
  virtual void update() = 0;
};

class subject {
 public:
  int get_state() {
    return state;
  }
  void set_state(int s) {
    state = s;
    notify_all();
  }
  void attach(cdps::observer* observer) {
    observers.push_back(observer);
  }
  void notify_all() {
    for (auto& obj : observers) {
      obj->update();
    }
  }

 private:
  int state;
  std::vector<cdps::observer*> observers;
};

class bin_observer : observer {
 public:
  bin_observer(cdps::subject* s) {
    sub = s;
    sub->attach(this);
  }
  void update() override {
    int state = sub->get_state();
    std::cout << "[BINARY]: " << decimal_to_binary(state) << std::endl;
  }

 private:
  std::string decimal_to_binary(int decimal) {
    return std::bitset<8>(decimal).to_string();
  }
};

class oct_observer : observer {
 public:
  oct_observer(cdps::subject* s) {
    sub = s;
    sub->attach(this);
  }
  void update() override {
    int state = sub->get_state();
    std::cout << "[OCTAL]: " << decimal_to_octal(state) << std::endl;
  }

 private:
  int decimal_to_octal(int decimal) {
    int rem, i = 1, octal = 0;
    while (decimal != 0) {
      rem = decimal % 8;
      decimal /= 8;
      octal += rem * i;
      i *= 10;
    }
    return octal;
  }
};

class hex_observer : observer {
 public:
  hex_observer(cdps::subject* s) {
    sub = s;
    sub->attach(this);
  }
  void update() override {
    int state = sub->get_state();
    std::cout << "[HEX]: " << decimal_to_hex(state) << std::endl;
  }

 private:
  std::string decimal_to_hex(int decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;
    return ss.str();
  }
};
}  // namespace cdps
