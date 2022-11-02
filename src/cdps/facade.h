#include <iostream>

namespace cdps {
class shape_maker {
 public:
  shape_maker() {
    circle = new cdps::circle_shape();
    rectangle = new cdps::rectangle_shape();
  }
  void draw_circle() {
    circle->draw();
  }
  void draw_rectangle() {
    rectangle->draw();
  }

 private:
  cdps::circle_shape* circle;
  cdps::rectangle_shape* rectangle;
};
}  // namespace cdps
