#include <iostream>

namespace cdps {
enum shape_type { circle, rectangle };
class shape;
class circle_shape;
class rectangle_shape;
class shape_factory {
 public:
  cdps::shape* get_shape(cdps::shape_type type) {
    if (cdps::shape_type::circle == type) {
      return new cdps::circle_shape();
    } else if (cdps::shape_type::rectangle == type) {
      return new cdps::rectangle_shape();
    }

    return nullptr;
  }
};
}  // namespace cdps
