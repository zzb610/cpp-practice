#include <iostream>
class A {
  int id;

public:
  A() : id(0) {
    std::cout << "default ctor. this=" << this << " id=" << id << std::endl;
  }
  A(int id) : id(id) {
    std::cout << "ctor. this=" << this << " id=" << id << std::endl;
  }
  ~A() { std::cout << "dctor. this=" << this << " id=" << id << std::endl; }
};

int main(void) {
  int size = 3;
  A *buf = new A[size];
  A *tmp = buf;

  std::cout << "buf=" << buf << " tmp=" << tmp << std::endl;

  for (int i = 0; i < size; ++i) {
    new (tmp++) A(i); // placement new
  }

  std::cout << "buf=" << buf << " tmp=" << tmp << std::endl;

  delete[] buf; // dctor的次序逆反

  return 0;

  // default ctor. this=0x5614a95e0eb8 id=0
  // default ctor. this=0x5614a95e0ebc id=0
  // default ctor. this=0x5614a95e0ec0 id=0
  // buf=0x5614a95e0eb8 tmp=0x5614a95e0eb8
  // ctor. this=0x5614a95e0eb8 id=0
  // ctor. this=0x5614a95e0ebc id=1
  // ctor. this=0x5614a95e0ec0 id=2
  // buf=0x5614a95e0eb8 tmp=0x5614a95e0ec4
  // dctor. this=0x5614a95e0ec0 id=2
  // dctor. this=0x5614a95e0ebc id=1
  // dctor. this=0x5614a95e0eb8 id=0
}