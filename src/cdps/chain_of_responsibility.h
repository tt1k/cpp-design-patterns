#include <iostream>

namespace cdps {
enum log_level : int32_t {
  log_level_debug,
  log_level_info,
  log_level_error,
};

class logger {
 public:
  log_level level;

  // = 0 tells the compiler that this method must be overridden by a derived class
  virtual void write(std::string message) = 0;
  void set_next(logger* next) {
    next_logger = next;
  }
  void log_message(log_level l, std::string message) {
    if (level <= l) {
      write(message);
    } else if (next_logger) {
      next_logger->log_message(l, message);
    }
  }

 private:
  logger* next_logger;
};

class debug_logger : public logger {
 public:
  debug_logger(log_level l) {
    level = l;
  }
  void write(std::string message) override {
    std::cout << "[DEBUG]: " << message << std::endl;
  }
};

class info_logger : public logger {
 public:
  info_logger(log_level l) {
    level = l;
  }
  void write(std::string message) override {
    std::cout << "[INFO]: " << message << std::endl;
  }
};

class error_logger : public logger {
 public:
  error_logger(log_level l) {
    level = l;
  }
  void write(std::string message) override {
    std::cout << "[ERROR]: " << message << std::endl;
  }
};
}  // namespace cdps
