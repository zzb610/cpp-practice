#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <new>
#include <string>
// #include
class Foo {
  int _id;
  long _data;
  std::string _str;

public:
  Foo() : _id(0) {
    std::cout << "default ctor. this=" << this << " id=" << _id << std::endl;
  }

  Foo(int id) : _id(id) {
    std::cout << "ctor. this=" << this << " id=" << _id << std::endl;
  }

  // ~Foo() { std::cout << "dctr. this=" << this << " id=" << _id << std::endl;
  // }
  virtual ~Foo() {
    std::cout << "dctr. this=" << this << " id=" << _id << std::endl;
  }

  static void *operator new(std::size_t size);
  static void operator delete(void *pdead, std::size_t size);
  static void *operator new[](std::size_t size);
  static void operator delete[](void *pdead, std::size_t size);
};

void *Foo::operator new(std::size_t size) {
  Foo *p = static_cast<Foo *>(malloc(size));
  std::cout << "Foo::operator new " << p << std::endl;
  return p;
}

void Foo::operator delete(void *pdead, std::size_t size) {
  std::cout << "Foo::operator delete " << pdead << " size: " << size
            << std::endl;
  free(pdead);
}

void *Foo::operator new[](std::size_t size) {
  Foo *p = static_cast<Foo *>(malloc(size));
  std::cout << "Foo::operator new[] " << p << std::endl;
  return p;
}

void Foo::operator delete[](void *pdead, std::size_t size) {
  std::cout << "Foo::operator delete[] " << pdead << " size: " << size
            << std::endl;
  free(pdead);
}

int main() {
  std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
  std::cout << "sizeof(long)=" << sizeof(long) << std::endl;
  std::cout << "sizeof(std::string)" << sizeof(std::string) << std::endl;
  std::cout << "sizeof(vptr)=" << sizeof(Foo *) << std::endl;
  std::cout << "sizeof(Foo)=" << sizeof(Foo) << std::endl;

  // Foo *p = new Foo(7);
  // delete p;

  // std::cout << "sizeof(std::size_t)= "<<sizeof(std::size_t) << std::endl;;
  // Foo *pArray = new Foo[5];
  // delete[] pArray;

  // global new/delete
  Foo* p2 = ::new Foo(7);
  ::delete p2;

  Foo* pArray2 = ::new Foo[5];
  ::delete[] pArray2;
  return 0;

// sizeof(int)=4
// sizeof(long)=8
// sizeof(std::string)32
// sizeof(vptr)=8
// sizeof(Foo)=56
// Foo::operator new 0x16ff2c0
// ctor. this=0x16ff2c0 id=7
// dctr. this=0x16ff2c0 id=7
// Foo::operator delete 0x16ff2c0 size: 56
// sizeof(std::size_t)= 8
// Foo::operator new[] 0x16ff300
// default ctor. this=0x16ff308 id=0
// default ctor. this=0x16ff340 id=0
// default ctor. this=0x16ff378 id=0
// default ctor. this=0x16ff3b0 id=0
// default ctor. this=0x16ff3e8 id=0
// dctr. this=0x16ff3e8 id=0
// dctr. this=0x16ff3b0 id=0
// dctr. this=0x16ff378 id=0
// dctr. this=0x16ff340 id=0
// dctr. this=0x16ff308 id=0


}