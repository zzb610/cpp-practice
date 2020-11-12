#include "num_sequence.h"

#include <iostream>

using std::cerr;

const int NumSequence::kMaxElems = 1024;

// dtor
NumSequence::~NumSequence() {}

bool NumSequence::CheckIntegrity(int pos, int size)
{
    if (pos <= 0 || pos > kMaxElems)
    {
        cerr << "!! invaild position: " << pos << " Cannot honor request\n";
        return false;
    }
    if (pos > size)
    {
        GenElems(pos);
    }
    return true;
}

ostream &operator<<(ostream &os, const NumSequence &ns)
{
    return ns.print(os);
}