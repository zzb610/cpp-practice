#include "nocopy.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    NoCopy c;
    // NoCopy c1(c); //  error: use of deleted function ‘NoCopy::NoCopy(const NoCopy&)’
    NoCopy c2;
    // c2 = c; // error: use of deleted function ‘NoCopy& NoCopy::operator=(const NoCopy&)’
    
    return 0; 
}
