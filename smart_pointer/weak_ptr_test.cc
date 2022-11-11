#include <iostream>
#include <memory>
int main(void) {
  std::shared_ptr<int> sp1(new int(666));
  std::cout << sp1.use_count() << "\n";

  std::weak_ptr<int> wp1(sp1);
  std::cout << wp1.use_count() << "\n";
  std::cout << sp1.use_count() << "\n";

  std::weak_ptr<int> wp2 = sp1;
  std::cout << sp1.use_count() << "\n";

  std::weak_ptr<int> wp3 = wp1;
  std::cout << sp1.use_count() << "\n";

  return 0;
}