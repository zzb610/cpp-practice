#include "widget.h"
int main(void){
  Widget w1;

  Widget w2(w1);

  Widget w3(std::move(w2));
  
  w2 = std::move(w3);

  auto w4 = w2;

  return 0;
}