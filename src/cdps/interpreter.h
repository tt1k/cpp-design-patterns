#include <iostream>
#include <map>

namespace cdps {
class context {
 public:
  void set_var(std::string s, bool b) {
    if (vars.find(s) != vars.end()) {
      vars[s] = b;
    }

    vars.insert(std::pair<std::string, bool>(s, b));
  }
  bool get_var(std::string s) {
    return vars[s];
  }

 private:
  std::map<std::string, bool> vars;
};

class expression {
 public:
  virtual bool interpret(cdps::context* context) = 0;
};

class terminal_expression : public expression {
 public:
  terminal_expression(std::string v) {
    value = v;
  }
  bool interpret(cdps::context* context) override {
    return context->get_var(value);
  }

 private:
  std::string value;
};

class non_terminal_expression : public expression {
 public:
  non_terminal_expression(cdps::expression* l, cdps::expression* r) {
    lhs = l;
    rhs = r;
  }
  bool interpret(cdps::context* context) override {
    return lhs->interpret(context) && rhs->interpret(context);
  }

 private:
  cdps::expression* lhs;
  cdps::expression* rhs;
};
}  // namespace cdps
