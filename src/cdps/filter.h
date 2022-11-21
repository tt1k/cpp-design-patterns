#include <iostream>

namespace cdps {
enum country : int32_t {
  country_china,
  country_usa,
};

class person {
 public:
  bool gender;
  std::string name;
  cdps::country country;
  person(bool g, std::string n, cdps::country c) {
    gender = g;
    name = n;
    country = c;
  }
};

class person_filter {
 public:
  virtual std::vector<cdps::person*> fit_filter(std::vector<cdps::person*> list) = 0;
};

class person_filter_male : public person_filter {
  std::vector<cdps::person*> fit_filter(std::vector<cdps::person*> list) override {
    std::vector<cdps::person*> ret;
    for (auto& item : list) {
      if (1 == item->gender) {
        ret.push_back(item);
      }
    }

    return ret;
  }
};

class person_filter_usa : public person_filter {
  std::vector<cdps::person*> fit_filter(std::vector<cdps::person*> list) override {
    std::vector<cdps::person*> ret;
    for (auto& item : list) {
      if (cdps::country_usa == item->country) {
        ret.push_back(item);
      }
    }

    return ret;
  }
};
}  // namespace cdps
