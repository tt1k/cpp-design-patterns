#include <iostream>
#include <vector>

namespace cdps {
class component {
 public:
  virtual void get(int i){};
  virtual void add(cdps::component* item){};
  virtual void remove(int i){};
  virtual void operation(){};
};
class composite : public component {
 public:
  void get(int i) override {
    return children[i];
  }
  void add(cdps::component* item) override {
    children.push_back(item);
  }
  void remove(int i) override {
    cdps::component* child = children[i];
    children.erase(children.begin() + i);
  }
  void operation() override {
    for (auto& item : children) {
      item->operation();
    }
  }

 private:
  std::vector<cdps::component*> children;
};
class leaf : public component {
 public:
  leaf(int i) {
    leaf_id = i;
  }
  void operation() override {
    std::cout << "[COMPOSITE]: leaf " << leaf_id << " doing operation" << std::endl;
  }

 private:
  int leaf_id;
};
}  // namespace cdps
