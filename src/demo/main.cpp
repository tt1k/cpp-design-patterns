#include <iostream>

#include <cdps/cdps.h>

#pragma mark - init

void init_cdps() {
  std::string version = cdps::version::get_version_in_cpp();
  std::cout << "cdps " << version << " initialized" << std::endl;
}

#pragma mark - singleton

void test_singleton() {
  cdps::singleton* p = cdps::singleton::get();
  std::cout << p->desc << std::endl;
}

#pragma mark - chain_of_responsibility

// cdps::logger* get_logger() {
//   cdps::logger* error_logger = new cdps::error_logger(cdps::log_level::log_level_error);
//   cdps::logger* info_logger = new cdps::info_logger(cdps::log_level::log_level_info);
//   cdps::logger* debug_logger = new cdps::debug_logger(cdps::log_level::log_level_debug);
//   error_logger->set_next(info_logger);
//   info_logger->set_next(debug_logger);

//   return error_logger;
// }

// void test_chain_of_responsibility() {
//   cdps::logger* logger = get_logger();
//   logger->log_message(cdps::log_level::log_level_info, "this is info");
// }

#pragma mark - main

int main(int argc, char* argv[]) {
  init_cdps();
  test_singleton();
  return 0;
}
