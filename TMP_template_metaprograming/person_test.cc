#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
class Person {
public:
  template <typename T, typename = std::enable_if_t<
                            !std::is_base_of_v<Person, std::decay_t<T>> &&
                            !std::is_integral_v<std::remove_reference_t<T>>>>
  explicit Person(T &&name) : name_(std::forward<T>(name)) {
    std::cout << "universal forward constructor\n";
  }

  explicit Person(int idx): name_(std::to_string(idx)){
    std::cout << "int constructor\n";
  }

private:
  std::string name_;
};

int main(void) { 

  Person p1("bz");
  Person p2(10);
  return 0; 
}