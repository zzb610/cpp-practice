#include <future>
#include <thread>
#include <iostream>
int DoWork(int in){
  std::cout << std::this_thread::get_id() << "\n";
  return in + 1;
}

int main() {

  std::cout << "main: " << std::this_thread::get_id() << "\n";
  auto res1 = std::async(std::launch::async, DoWork, 5);
  auto res2 = std::async(std::launch::async, DoWork, 6);

  auto v1 = res1.get();
  auto v2 = res2.get();

  std::cout << v1 << "\n";
  std::cout << v2 << "\n";
  return 0;

}