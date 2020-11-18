<<<<<<< HEAD:num_sequence/num_sequece.cc
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
=======
#include "num_sequence.h"

#include <iostream>

using std::cerr;

const int NumSequence::kMaxElems = 1024;

// dtor
NumSequence::~NumSequence() {}

int NumSequence::Elem(int pos)
{
    if(!CheckIntegrity(pos, relems_.size()))
    {
        return 0;
    }

    return relems_[];
}

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

>>>>>>> 42dd1595a04f4dc91aa43058a60f34cb19240577:num_sequence/num_sequence.cc
