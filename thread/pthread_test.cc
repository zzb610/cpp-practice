#include <cstdio>
#include <pthread.h>
#include <unistd.h>

void *ThreadFunc(void *arg) {
  while (1) {
    sleep(1);

    printf("I am New Thread!\n");
  }
  return nullptr;
}

int main(void) {

  pthread_t thread_id;
  pthread_create(&thread_id, nullptr, ThreadFunc, nullptr);

  // main thread
  while (1) {
  }

  return 0;
}