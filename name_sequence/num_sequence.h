#ifndef __NUM_SEQUENCE_H__
#define __NUM_SEQUENCE_H__

#include <iostream>
using std::cout;
using std::ostream;

class NumSequence;
ostream &operator<<(ostream &os, const NumSequence &ns);

class NumSequence
{
public:
    // dtor
    virtual ~NumSequence();

    virtual int Elem(int pos) const = 0;
    virtual const char *WhatAMI() const = 0;
    static int MaxElems() { return kMaxElems; }
    virtual ostream &print(ostream &os = cout) const = 0;

protected:
    virtual void GenElems(int pos) const = 0;
    bool CheckIntegrity(int pos) const;
    const static int kMaxElems;

    friend ostream &operator<<(ostream &os, const NumSequence &ns);
};

#endif // __NUM_SEQUENCE_H__