#include <iostream>

namespace cdps {

#pragma mark - simple factory

class phone {
 public:
  virtual void use() = 0;
};

class phone_apple : public phone {
 public:
  void use() override {
    std::cout << "use phone apple" << std::endl;
  }
};

class phone_huawei : public phone {
 public:
  void use() override {
    std::cout << "use phone huawei" << std::endl;
  }
};

class simple_factory {
 public:
  cdps::phone* get_phone(std::string name) {
    if ("apple" == name) {
      return new cdps::phone_apple();
    } else if ("huawei" == name) {
      return new cdps::phone_huawei();
    } else {
      return nullptr;
    }
  }
};

#pragma mark - factory method

class factory {
 public:
  virtual cdps::phone* factory_method() = 0;
};

class factory_apple : public factory {
 public:
  cdps::phone* factory_method() override {
    return new cdps::phone_apple();
  }
};

class factory_huawei : public factory {
 public:
  cdps::phone* factory_method() override {
    return new cdps::phone_huawei();
  }
};

#pragma mark - abstract factory

class car {
 public:
  virtual void drive() = 0;
};

class car_apple : public car {
 public:
  void drive() override {
    std::cout << "use car apple" << std::endl;
  }
};

class car_huawei : public car {
 public:
  void drive() override {
    std::cout << "use car huawei" << std::endl;
  }
};

class abstract_factory {
 public:
  virtual cdps::phone* abstract_phone() = 0;
  virtual cdps::car* abstract_car() = 0;
};

class apple_factory : public abstract_factory {
  cdps::phone* abstract_phone() override {
    return new cdps::phone_apple();
  }
  cdps::car* abstract_car() override {
    return new cdps::car_apple();
  }
};

class huawei_factory : public abstract_factory {
  cdps::phone* abstract_phone() override {
    return new cdps::phone_huawei();
  }
  cdps::car* abstract_car() override {
    return new cdps::car_huawei();
  }
};
}  // namespace cdps
