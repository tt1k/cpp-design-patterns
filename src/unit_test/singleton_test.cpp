#include "../patterns/singleton.hpp"

#include <iostream>

int main() {
  cdps::singleton* p = cdps::singleton::get();
  std::cout << p->desc << std::endl;
}
