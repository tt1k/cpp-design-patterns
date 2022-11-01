#include <iostream>

namespace cdps {
class shape {
 public:
  virtual void draw() = 0;
};

class circle_shape : public shape {
 public:
  void draw() override {
    std::cout << "draw circle" << std::endl;
  }
};

class rectangle_shape : public shape {
 public:
  void draw() override {
    std::cout << "rectangle circle" << std::endl;
  }
};

class shape_decorator : public shape {
 public:
  cdps::shape* decorated_shape;
  shape_decorator(cdps::shape* shape) {
    decorated_shape = shape;
  }
  void draw() {
    decorated_shape->draw();
  }
};

class red_shape_decorator : public shape_decorator {
 public:
  red_shape_decorator(cdps::shape* shape) : shape_decorator(shape) {
  }
  void draw() {
    decorated_shape->draw();
    set_red_border();
  }
  void set_red_border() {
    std::cout << "current shape set red border" << std::endl;
  }
};
}  // namespace cdps
