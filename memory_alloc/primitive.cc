#include <complex>
#include <cstdlib>
#include <memory>
#include <new>
#include <ext/pool_allocator.h> // __gnu_cxx::__pool_alloc
int main(void) {

  // 4 primitive ways to allocate memory in c++

  // malloc and free
  void *p = malloc(4);
  free(p);

  // new and delete expr
  std::complex<int> *p_complex = new std::complex<int>();
  delete p_complex;

  // operator new and operator
  void *p2 = ::operator new(4);
  ::operator delete(p2);

#ifdef __GNUC__
  // non-static func, invoke by object (std::allocator)
  void *p3 = std::allocator<int>().allocate(512);
  std::allocator<int>().deallocate((int *)p3, 512);

  // non-static func, invoke by object (std::allocator)
  void *p5 = __gnu_cxx::__pool_alloc<int>().allocate(9);
  __gnu_cxx::__pool_alloc<int>().deallocate((int *)p5, 9);
#endif

  return 0;
}