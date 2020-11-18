#ifndef __NUM_SEQUENCE_H__
#define __NUM_SEQUENCE_H__

#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

class NumSequence;
ostream &operator<<(ostream &os, const NumSequence &ns);

class NumSequence
{
public:
    // dtor
    virtual ~NumSequence();

    virtual ostream &print(ostream &os = cout) const;

    virtual int Elem(int pos);
    virtual const char *WhatAMI() const = 0;

    int length() const { return length_; }
    int beg_pos() const { return beg_pos_; }
    static int MaxElems() { return kMaxElems; }

protected:
    virtual void GenElems(int pos) const = 0;
    virtual bool CheckIntegrity(int pos, int size);

    NumSequence(int len, int bp, vector<int> &re) : length_(len), beg_pos_(bp), relems_(re) {}

    int length_;
    int beg_pos_;
    vector<int> &relems_;
    const static int kMaxElems;

    friend ostream &operator<<(ostream &os, const NumSequence &ns);
};

#endif // __NUM_SEQUENCE_H__