#include <iostream>
#include <vector>

namespace cdps {
class mediator;

class colleague {
 public:
  virtual int get_id() = 0;
  virtual void send(std::string) = 0;
  virtual void receive(std::string m) = 0;

 protected:
  cdps::mediator* mediator;
  int index;
};

class mediator {
 public:
  virtual void add(cdps::colleague* c) = 0;
  virtual void distribute(cdps::colleague* c, std::string m) = 0;
};

class concrete_colleague : public colleague {
 public:
  concrete_colleague(cdps::mediator* m, int i) {
    mediator = m;
    index = i;
  }
  int get_id() override {
    return index;
  }
  void send(std::string m) override {
    std::cout << "Message send by " << index << ": " << m << std::endl;
    mediator->distribute(this, m);
  }
  void receive(std::string m) override {
    std::cout << "Message received by " << index << ": " << m << std::endl;
  }
};

class concrete_mediator : public mediator {
 public:
  void add(cdps::colleague* c) override {
    colleagues.push_back(c);
  }
  void distribute(cdps::colleague* c, std::string m) override {
    for (auto& it : colleagues) {
      if (it->get_id() != c->get_id()) {
        it->receive(m);
      }
    }
  }

 private:
  std::vector<cdps::colleague*> colleagues;
};
}  // namespace cdps
