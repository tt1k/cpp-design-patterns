#include "../patterns/chain_of_responsibility.hpp"

#include <iostream>

cdps::logger* get_logger() {
  cdps::logger* error_logger = new cdps::error_logger(cdps::log_level::log_level_error);
  cdps::logger* info_logger = new cdps::info_logger(cdps::log_level::log_level_info);
  cdps::logger* debug_logger = new cdps::debug_logger(cdps::log_level::log_level_debug);
  error_logger->set_next(info_logger);
  info_logger->set_next(debug_logger);

  return error_logger;
}

int main() {
  cdps::logger* logger = get_logger();
  logger->log_message(cdps::log_level::log_level_info, "this is info");
}
