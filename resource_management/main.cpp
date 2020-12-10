#include <iostream>

#include <memory>

class Mutex;
class MutexLock
{
public:
    MutexLock(Mutex m) : _lock(m) { _lock.acquire(); }
    ~MutexLock() { _lock.release(); }

private:
    Mutex &_lock;
};

using std::auto_ptr;
void f()
{
    auto_ptr<int> p(new int);
    MutexLock m1(m);
    process(p);
}
int main(int, char **)
{
    std::cout << "Hello, world!\n";
}
