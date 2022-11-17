#include <memory>
#include <mutex>

using LockGuardT = std::lock_guard<std::mutex>;

class Weight {};

int func1(std::shared_ptr<Weight>) { return 0; }

template <typename FuncT, typename MutexT, typename PtrT>
decltype(auto) LockAndCall(FuncT func, MutexT &mutex, PtrT ptr) {

  LockGuardT guard(mutex);

  return func(ptr);
}

int main(void) {

  std::mutex m1;

  auto w1 = std::make_shared<Weight>();

  LockAndCall(func1, m1, w1);

  return 0;
}