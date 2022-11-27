#include <cstdint>
struct IPv4Header {
  std::uint32_t version : 4, IHL : 4, DSCP : 6, ECN : 2, totalLength : 16;
};

int main(void){

  IPv4Header header;
  
  return 0;
}