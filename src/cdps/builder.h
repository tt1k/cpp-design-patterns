#include <iostream>
#include <string>

namespace cdps {
class house {
 public:
  std::string walls;
  std::string doors;
  std::string roofs;
  void show() {
    std::cout << "walls: " << walls << std::endl;
    std::cout << "doors: " << doors << std::endl;
    std::cout << "roofs: " << roofs << std::endl;
  }
};

class builder {
 public:
  virtual void build_walls() = 0;
  virtual void build_doors() = 0;
  virtual void build_roofs() = 0;
  cdps::house* get_house() {
    return house;
  }
  builder() {
    house = new cdps::house();
  }

 protected:
  cdps::house* house;
};

class apple_builder : public builder {
  void build_walls() override {
    house->walls = "apple walls";
  }
  void build_doors() override {
    house->doors = "apple doors";
  }
  void build_roofs() override {
    house->roofs = "apple roofs";
  }
};

class huawei_builder : public builder {
  void build_walls() override {
    house->walls = "huawei walls";
  }
  void build_doors() override {
    house->doors = "huawei doors";
  }
  void build_roofs() override {
    house->roofs = "huawei roofs";
  }
};

class director {
 public:
  director(cdps::builder* b) {
    builder = b;
  }
  void change_builder(cdps::builder* b) {
    builder = b;
  }
  cdps::house* make() {
    builder->build_walls();
    builder->build_doors();
    builder->build_roofs();
    return builder->get_house();
  }

 private:
  cdps::builder* builder;
};
}  // namespace cdps
