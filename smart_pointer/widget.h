#pragma once
#include <memory>

class Widget {

public:

  // construct
  Widget();
  ~Widget();

  // copy
  Widget (const Widget& rhs);
  Widget& operator=(const Widget& rhs);

  // move
  Widget (Widget&& rhs);
  Widget& operator=(Widget&& rhs);


private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;
};