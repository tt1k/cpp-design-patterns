#include <iostream>
#include <map>

namespace cdps {
class flyweight_item {
 public:
  flyweight_item(int s) {
    state = s;
  }
  void operation() {
    std::cout << "[FLYWEIGHT]: Item state " << state << std::endl;
  }

 private:
  int state;
};
class flyweight_factory {
 public:
  flyweight_item* get_flyweight_item(int key) {
    if (pool.find(key) != pool.end()) {
      std::cout << "[FLYWEIGHT]: Got " << key << " in pool" << std::endl;
      return pool[key];
    }
    flyweight_item* tmp = new flyweight_item(key);
    pool.insert(std::pair<int, flyweight_item*>(key, tmp));
    return tmp;
  }

 private:
  std::map<int, flyweight_item*> pool;
};
}  // namespace cdps
