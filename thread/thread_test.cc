#include <cstdio>
#include <thread>

void ThreadProc1() {
  while (true) {
    printf("I am New Thread 1.\n");
  }
}

void ThreadProc2(int a, int b) {
  while (true) {
    printf("I am New Thread 2.\n ");
  }
}

int main(void) {

  std::thread t1(ThreadProc1);

  std::thread t2(ThreadProc2, 1, 2);

  while (true) {
  }

  return 0;
}