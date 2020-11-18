<<<<<<< HEAD
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

    virtual int Elem(int pos) = 0;
    virtual const char *WhatAMI() const = 0;
    static int MaxElems() { return kMaxElems; }
    virtual ostream &print(ostream &os = cout) const = 0;

protected:
    virtual void GenElems(int pos) const = 0;
    virtual bool CheckIntegrity(int pos, int size);
    const static int kMaxElems;

    friend ostream &operator<<(ostream &os, const NumSequence &ns);
};

=======
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

>>>>>>> 42dd1595a04f4dc91aa43058a60f34cb19240577
#endif // __NUM_SEQUENCE_H__