#include <iostream>
#include <vector>

namespace cdps {
class memento {
 public:
  int state;
  memento(int s) {
    state = s;
  }
};

class originator {
 public:
  int get_state() {
    return state;
  }
  void set_state(int s) {
    state = s;
  }
  cdps::memento* save_memento() {
    return new cdps::memento(state);
  }
  void read_memento(cdps::memento* m) {
    state = m->state;
  }

 private:
  int state;
};

class care_taker {
 public:
  void add_memento(cdps::memento* m) {
    list.push_back(m);
  }
  cdps::memento* get_memento(int index) {
    return index < list.size() ? list[index] : nullptr;
  }

 private:
  std::vector<cdps::memento*> list;
};

}  // namespace cdps
