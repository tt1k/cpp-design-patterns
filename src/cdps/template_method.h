#include <iostream>

namespace cdps {
class template_game {
 public:
  virtual void init() = 0;
  virtual void start() = 0;

  virtual void play() {
    init();
    start();
  }
};

class football_game : public template_game {
  void init() override {
    std::cout << "football_game init" << std::endl;
  }
  void start() override {
    std::cout << "football_game start" << std::endl;
  }
};

class cricket_game : public template_game {
  void init() override {
    std::cout << "cricket_game init" << std::endl;
  }
  void start() override {
    std::cout << "cricket_game start" << std::endl;
  }
};
}  // namespace cdps
