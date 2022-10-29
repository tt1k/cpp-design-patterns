#include <cdps/version.h>

namespace cdps {
std::string version::version_str = "1.0.0";
std::string version::get_version_in_cpp() {
  return version_str;
}
}  // namespace cdps
