#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include "num_sequence.h"

#include <vector>
using std::vector;

class Fibonacci : public NumSequence
{
public:
    Fibonacci(int len = 1, int beg_pos = 1) : length_(len), beg_pos_(beg_pos) {}

    virtual int Elem(int pos);

    virtual const char *WhatAMI() const { return "Fibonacci"; };
    virtual ostream &print(ostream &os = cout) const;

    int length() const { return length_; }
    int beg_pos() const { return beg_pos_; }

    // ~Fibonacci(){};

protected:
    virtual void GenElems(int pos) const;
    int length_;
    int beg_pos_;
    static vector<int> elems_;
};

#endif // __FIBONACCI_H__