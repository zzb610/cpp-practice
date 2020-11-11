#ifndef __TRIANGULAR__
#define __TRIANGULAR__

#include <string>
#include <vector>
#include <iostream>
#include "tirangular_iterator.h"
using std::cout;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Triangular;
ostream &operator<<(ostream &os, const Triangular &rhs);
istream &operator>>(istream &is, Triangular &rhs);

class Triangular
{
public:
    Triangular(int length = 1, int beg_pos = 1);
    Triangular(const Triangular &rhs);

    int length() const { return length_; }
    int beg_pos() const { return beg_pos_; }

    void length(int len) { length_ = len; }
    void beg_pos(int bp) { beg_pos_ = bp; }

    int elem(int pos) const;

    bool next(int &val) const;
    void NextReset() { next_ = beg_pos_ - 1; }

    Triangular &copy(const Triangular &rhs);

    static bool IsElem(int value);
    static void GenElems(int length);
    static void GenElemsToValue(int value);
    static void display(int length, int beg_pos, ostream &os = cout);
    static const int kMaxElems;

    typedef TriangularIterator iterator;
    TriangularIterator begin() const
    {
        return TriangularIterator(beg_pos_);
    }
    TriangularIterator end() const
    {
        return TriangularIterator(beg_pos_ + length_);
    }

private:
    int length_;
    int beg_pos_;
    mutable int next_;
    string name_;
    static vector<int> elems_;

    friend class TriangularIterator;
    friend ostream &operator<<(ostream &os, const Triangular &rhs);
    friend istream &operator>>(istream &is, Triangular &rhs);
};

#endif // __TRIANGULAR