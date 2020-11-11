#include "num_sequence.h"

#include <iostream>
using std::cerr;
// dtor
NumSequence::~NumSequence() {}

bool NumSequence::CheckIntegrity(int pos) const
{
    if (pos <= 0 || pos > kMaxElems)
    {
        cerr << "!! invaild position: " << pos << " Cannot honor request\n";
        return false;
    }
    return true;
}

ostream &operator<<(ostream &os, const NumSequence &ns)
{
    return ns.print(os);
}