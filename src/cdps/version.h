#include <iostream>

namespace cdps {
class version {
 private:
  static std::string version_str;

 public:
  static std::string get_version_in_cpp();
  static std::string get_version() {
    return version_str;
  }
};
}  // namespace cdps
