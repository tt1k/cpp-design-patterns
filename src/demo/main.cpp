#include <cdps/cdps.h>

#include <iostream>

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

cdps::logger* get_logger() {
  cdps::logger* error_logger = new cdps::error_logger(cdps::log_level::log_level_error);
  cdps::logger* info_logger = new cdps::info_logger(cdps::log_level::log_level_info);
  cdps::logger* debug_logger = new cdps::debug_logger(cdps::log_level::log_level_debug);
  error_logger->set_next(info_logger);
  info_logger->set_next(debug_logger);

  return error_logger;
}

void test_chain_of_responsibility() {
  cdps::logger* logger = get_logger();
  logger->log_message(cdps::log_level::log_level_debug, "this is debug");
  logger->log_message(cdps::log_level::log_level_info, "this is info");
  logger->log_message(cdps::log_level::log_level_error, "this is error");
}

#pragma mark - observer

void test_observer() {
  cdps::subject* sub = new cdps::subject();
  new cdps::bin_observer(sub);
  new cdps::oct_observer(sub);
  new cdps::hex_observer(sub);

  sub->set_state(10);
  sub->set_state(15);
}

#pragma mark - decorator

void test_decorator() {
  cdps::circle_shape* circle = new cdps::circle_shape();
  circle->draw();

  cdps::shape_decorator* circle_decorator = new cdps::red_shape_decorator(circle);
  circle_decorator->draw();

  cdps::rectangle_shape* rectangle = new cdps::rectangle_shape();
  rectangle->draw();

  cdps::shape_decorator* rectangle_decorator = new cdps::red_shape_decorator(rectangle);
  rectangle_decorator->draw();
}

#pragma mark - visitor

void test_visitor() {
  cdps::computer_protocol* computer = new cdps::computer();
  cdps::computer_part_display_visitor* visitor = new cdps::computer_part_display_visitor();
  computer->accept(visitor);
}

#pragma mark - facade

void test_facade() {
  cdps::shape_maker* makder = new cdps::shape_maker();
  makder->draw_circle();
  makder->draw_rectangle();
}

#pragma mark - factory

void test_single_factory() {
  cdps::simple_factory* factory = new cdps::simple_factory();

  cdps::phone* apple = factory->get_phone("apple");
  apple->use();

  cdps::phone* huawei = factory->get_phone("huawei");
  huawei->use();
}

void test_factory_method() {
  cdps::factory* factory;

  factory = new cdps::factory_apple();
  cdps::phone* apple = factory->factory_method();
  apple->use();

  factory = new cdps::factory_huawei();
  cdps::phone* huawei = factory->factory_method();
  huawei->use();
}

void test_abstract_factory() {
  cdps::abstract_factory* factory;
  cdps::car* car;
  cdps::phone* phone;

  factory = new cdps::apple_factory();
  car = factory->abstract_car();
  car->drive();
  phone = factory->abstract_phone();
  phone->use();

  factory = new cdps::huawei_factory();
  car = factory->abstract_car();
  car->drive();
  phone = factory->abstract_phone();
  phone->use();
}

void test_factory() {
  std::cout << "[note]: single_factory" << std::endl;
  test_single_factory();
  std::cout << "\n[note]: factory_method" << std::endl;
  test_factory_method();
  std::cout << "\n[note]: abstract_factory" << std::endl;
  test_abstract_factory();
}

#pragma mark - bridge

void test_bridge() {
  cdps::implementor* impl_a = new cdps::concrete_implementor_a();
  cdps::implementor* impl_b = new cdps::concrete_implementor_b();
  cdps::abstraction* abstract = nullptr;
  abstract = new cdps::refined_abstraction(impl_a);
  abstract->operation();
  abstract = new cdps::refined_abstraction(impl_b);
  abstract->operation();
}

#pragma mark - proxy

void test_proxy() {
  cdps::proxy* obj = new cdps::proxy();
  obj->operation();
}

#pragma mark - fly_weight

void test_fly_weight() {
  cdps::flyweight_factory* factory = new cdps::flyweight_factory();
  factory->get_flyweight_item(1)->operation();
  factory->get_flyweight_item(2)->operation();
  factory->get_flyweight_item(1)->operation();
}

#pragma mark - prototype

cdps::prototype* cdps::prototype_client::types[2];
int cdps::prototype_client::types_count = 2;

void test_prototype() {
  cdps::prototype_client::init();
  cdps::prototype* a = cdps::prototype_client::make(0);
  std::cout << a->type() << std::endl;
  cdps::prototype* b = cdps::prototype_client::make(1);
  std::cout << b->type() << std::endl;
}

#pragma mark - composite

void test_composite() {
  cdps::composite* composite = new cdps::composite();
  for (int i = 0; i < 5; i++) {
    cdps::leaf* child = new cdps::leaf(i);
    composite->add(child);
  }

  composite->remove(2);
  composite->operation();
}

#pragma mark - adapter

void test_class_adapter() {
  cdps::class_target* target = new cdps::class_adapter();
  target->request();
}

void test_object_adapter() {
  cdps::object_target* target = new cdps::object_adapter();
  target->request();
}

void test_adapter() {
  test_class_adapter();
  test_object_adapter();
}

#pragma mark - builder

void test_builder() {
  cdps::director* director = new cdps::director(new cdps::apple_builder());

  cdps::house* house = director->make();
  house->show();

  director->change_builder(new cdps::huawei_builder());
  house = director->make();
  house->show();
}

#pragma mark - main

int main(int argc, char* argv[]) {
  init_cdps();
  test_builder();
  return 0;
}
