#include <iostream>
#include <vector>

namespace cdps {
class iterator {
 public:
  virtual bool has_next() = 0;
  virtual void next() = 0;
  virtual int current_value() = 0;
};

class int_container {
 public:
  cdps::iterator* get_iterator() {
    return it;
  }
  int_container() {
    it = new int_container_iterator(this);
  }
  void push_back(int i) {
    list.push_back(i);
  }
  unsigned long size() {
    return list.size();
  }
  int at(unsigned int index) {
    return list[index];
  }

 private:
  cdps::iterator* it;
  std::vector<int> list;
  class int_container_iterator : public iterator {
   public:
    int_container_iterator(cdps::int_container* c) {
      container = c;
      index = 0;
    }
    bool has_next() override {
      return index >= container->size() ? false : true;
    }
    void next() override {
      index++;
    }
    int current_value() override {
      return container->at(index);
    }

   private:
    cdps::int_container* container;
    unsigned int index;
  };
};
}  // namespace cdps
