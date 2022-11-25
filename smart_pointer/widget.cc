#include "widget.h"

#include <memory>
#include <string>
#include <vector>

struct Widget::Impl {
  std::string name;
  std::vector<int> data;
};

// construct
Widget::Widget() : pImpl(std::make_unique<Impl>()){};
Widget::~Widget() = default;

// copy
Widget::Widget(const Widget &rhs) : pImpl(std::make_unique<Impl>(*rhs.pImpl)) {}
Widget &Widget::operator=(const Widget &rhs) {
  *pImpl = *rhs.pImpl;
  return *this;
}

// move
Widget::Widget(Widget &&rhs) = default;
Widget &Widget::operator=(Widget &&rhs) = default;
