#include <utility>
#include <vector>
#include <iostream>

template <typename Container, typename Index>
decltype(auto) AuthAndSuccess(Container &&c, Index i) {

  return std::forward<Container>(c)[i];
}

std::vector<int> MakeIntVec() { return std::vector<int>{11, 22, 33, 44}; }

int main(void) {

  std::vector<int> vec{1, 2, 3, 4, 5};

  std::cout << "before: ";
  for(const auto& c: vec){
    std::cout << c << " ";
  }
  std::cout << "\n";

  AuthAndSuccess(vec, 1) = 99;

  std::cout << "after: ";
  for(const auto& c: vec){
    std::cout << c << " ";
  }
  std::cout << "\n";

  auto& rc = AuthAndSuccess(vec, 2);
  rc = 88;
  std::cout << "after: ";
  for(const auto& c: vec){
    std::cout << c << " ";
  }
  std::cout << "\n";

  auto c = AuthAndSuccess(MakeIntVec(), 5);
  std::cout << "c: " << c << "\n";
}