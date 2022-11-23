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

#pragma mark - filter

void test_filter() {
  std::vector<cdps::person*> list;
  list.push_back(new cdps::person(1, "Allen", cdps::country_usa));
  list.push_back(new cdps::person(0, "Targaryen", cdps::country_usa));
  list.push_back(new cdps::person(1, "Stark", cdps::country_usa));
  list.push_back(new cdps::person(1, "Xi", cdps::country_china));

  cdps::person_filter* male_filter = new cdps::person_filter_male();
  std::vector<cdps::person*> males = male_filter->fit_filter(list);
  std::cout << "males:" << std::endl;
  for (auto& item : males) {
    std::cout << item->name << std::endl;
  }

  cdps::person_filter* use_filter = new cdps::person_filter_usa();
  std::vector<cdps::person*> usas = use_filter->fit_filter(list);
  std::cout << "usas:" << std::endl;
  for (auto& item : usas) {
    std::cout << item->name << std::endl;
  }
}

#pragma mark - command

void test_command() {
  cdps::receiver* receiver = new cdps::receiver();
  cdps::command* add = new cdps::add_command(receiver);
  cdps::command* sub = new cdps::sub_command(receiver);

  cdps::invoker* invoker = new cdps::invoker();
  invoker->set_command(add);
  invoker->set_command(sub);
  invoker->comfirm_command();
}

#pragma mark - interpreter

void test_interpreter() {
  cdps::expression* lhs = new cdps::terminal_expression("A");
  cdps::expression* rhs = new cdps::terminal_expression("B");
  cdps::expression* and_expr = new cdps::non_terminal_expression(lhs, rhs);

  cdps::context* context = new cdps::context();
  context->set_var("A", true);
  context->set_var("B", true);
  std::cout << "A " << context->get_var("A") << " AND B " << context->get_var("B") << " is " << and_expr->interpret(context) << std::endl;

  context->set_var("B", false);
  std::cout << "A " << context->get_var("A") << " AND B " << context->get_var("B") << " is " << and_expr->interpret(context) << std::endl;

  context->set_var("A", false);
  std::cout << "A " << context->get_var("A") << " AND B " << context->get_var("B") << " is " << and_expr->interpret(context) << std::endl;
}

#pragma mark - iterator

void test_iterator() {
  cdps::int_container* container = new cdps::int_container();
  container->push_back(1);
  container->push_back(2);
  container->push_back(3);

  for (cdps::iterator* it = container->get_iterator(); it->has_next(); it->next()) {
    std::cout << it->current_value() << std::endl;
  }
}

#pragma mark - mediator

void test_mediator() {
  cdps::mediator* mediator = new cdps::concrete_mediator();

  cdps::colleague* c1 = new cdps::concrete_colleague(mediator, 1);
  mediator->add(c1);
  cdps::colleague* c2 = new cdps::concrete_colleague(mediator, 2);
  mediator->add(c2);
  cdps::colleague* c3 = new cdps::concrete_colleague(mediator, 3);
  mediator->add(c3);

  c1->send("Hi, I'm C1");
  c2->send("Hi, I'm C2");
  c3->send("Hi, I'm C3");
}

#pragma mark - memento

void test_memento() {
  cdps::originator* ori = new cdps::originator();
  cdps::care_taker* care_taker = new cdps::care_taker();

  ori->set_state(100);
  ori->set_state(200);
  care_taker->add_memento(ori->save_memento());
  ori->set_state(300);
  care_taker->add_memento(ori->save_memento());
  ori->set_state(400);

  std::cout << "current state: " << ori->get_state() << std::endl;
  std::cout << "first saved state: " << care_taker->get_memento(0)->state << std::endl;
  std::cout << "second saved state: " << care_taker->get_memento(1)->state << std::endl;
}

#pragma mark - main

int main(int argc, char* argv[]) {
  init_cdps();
  test_memento();
  return 0;
}
