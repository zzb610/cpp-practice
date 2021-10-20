#include <cstdio>

class Sigleton {
private:
  Sigleton() {}
  static Sigleton *p;

public:
  static Sigleton *instance();
};

Sigleton *Sigleton::p = nullptr;

Sigleton *Sigleton::instance() {
  if (p == nullptr) {
    p = new Sigleton();
  }
  return p;
}

int main(void) { return 0; }