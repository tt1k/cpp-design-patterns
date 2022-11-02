#include <iostream>

namespace cdps {
class monitor;
class mouse;
class keyboard;
class computer;

class computer_part_visitor {
 public:
  virtual void visit(cdps::mouse* mouse) = 0;
  virtual void visit(cdps::monitor* monitor) = 0;
  virtual void visit(cdps::keyboard* keyboard) = 0;
  virtual void visit(cdps::computer* keyboard) = 0;
};

class computer_part_display_visitor : public computer_part_visitor {
 public:
  void visit(cdps::mouse* mouse) override {
    std::cout << "[DISPLAY VISITOR]: visit mouse" << std::endl;
  }
  void visit(cdps::monitor* monitor) override {
    std::cout << "[DISPLAY VISITOR]: visit monitor" << std::endl;
  }
  void visit(cdps::keyboard* keyboard) override {
    std::cout << "[DISPLAY VISITOR]: visit keyboard" << std::endl;
  }
  void visit(cdps::computer* computer) override {
    std::cout << "[DISPLAY VISITOR]: visit computer" << std::endl;
  }
};

class computer_protocol {
 public:
  virtual void accept(cdps::computer_part_visitor* visitor) = 0;
};

class monitor : public computer_protocol {
 public:
  void accept(cdps::computer_part_visitor* visitor) override {
    visitor->visit(this);
  }
};

class mouse : public computer_protocol {
 public:
  void accept(cdps::computer_part_visitor* visitor) override {
    visitor->visit(this);
  }
};

class keyboard : public computer_protocol {
 public:
  void accept(cdps::computer_part_visitor* visitor) override {
    visitor->visit(this);
  }
};

class computer : public computer_protocol {
 public:
  computer() {
    parts = {new cdps::mouse(), new cdps::monitor(), new cdps::keyboard()};
  }
  void accept(cdps::computer_part_visitor* visitor) override {
    for (auto& part : parts) {
      part->accept(visitor);
    }
    visitor->visit(this);
  }

 private:
  std::vector<cdps::computer_protocol*> parts;
};
}  // namespace cdps
