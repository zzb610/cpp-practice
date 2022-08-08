#include <cstddef>
#include <iostream>
class Screen {
  int i;

  Screen *next;
  static Screen *freeStore;
  static const int screenChunk; // chunk number
public:
  Screen(int i) : i(i) {
    std::cout << "ctor. this=" << this << " i=" << i << std::endl;
  };
  int get() { return i; }

  // static void *operator new(std::size_t size);
  // static void operator delete(void *p, std::size_t size);
};

Screen *Screen::freeStore = 0;
const int Screen::screenChunk = 24;

// void *Screen::operator new(std::size_t size) {
//   Screen *p;
//   if (!freeStore) {
//     // allocate memory pool
//     size_t chunk = screenChunk * size;
//     freeStore = p = reinterpret_cast<Screen *>(new char[chunk]);
//     // assign next
//     for (; p != &freeStore[screenChunk - 1]; ++p) {
//       p->next = (p + 1);
//     }
//     p->next = 0;
//   }
//   // get first free chunk
//   p = freeStore;
//   // update first free chunk
//   freeStore = freeStore->next;
//   return p;
// }

// void Screen::operator delete(void *p, std::size_t size) {
//   (static_cast<Screen *>(p))->next = freeStore;
//   freeStore = static_cast<Screen *>(p);
// }

int main(void) {
  std::cout << "sizeof(Screen)=" << sizeof(Screen) << std::endl; // 16

  size_t const N = 100;
  Screen *p[N];
  // 有cookie, 间隔16( sizeof(Screen) )
  // 无cookie，间隔32( sizeof(Screen) + sizeof(size_t)*2 )
  for (int i = 0; i < N; ++i) {
    p[i] = new Screen(i);
  }

  for (int i = 0; i < 10; ++i) {
    std::cout << p[i] << std::endl;
  }

  for (int i = 0; i < N; ++i) {
    delete p[i];
  }
  return 0;
}
