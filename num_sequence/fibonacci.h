#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include "num_sequence.h"

#include <vector>
using std::vector;

class Fibonacci : public NumSequence
{
public:
    virtual const char *WhatAMI() const { return "Fibonacci"; };

protected:
    virtual void GenElems(int pos) const;
    static vector<int> elems_;
};

#endif // __FIBONACCI_H__