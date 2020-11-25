#ifndef __NUM_SEQUNCE_H__
#define __NUM_SEQUNCE_H__

#include <vector>
#include <vector>
using std::vector;

template <int len, int beg_pos>
class NumSequence
{
public:
    virtual ~NumSequence();
    int elem(int pos) const;

protected:
    virtual void GenElems(int pos) const = 0;
    bool CheckIntegrity(int pos, int size) const;
    NumSequence(vector<int> *pe);
    static const int kMaxElems;
    vector<int> *pelems_;
};
template <int len, int beg_pos>
NumSequence<len, beg_pos>::~NumSequence()
{
}

template <int len, int beg_pos>
int NumSequence<len, beg_pos>::elem(int pos) const
{
}

template <int len, int beg_pos>
bool NumSequence<len, beg_pos>::CheckIntegrity(int pos, int size) const
{
    if (pos <= 0 || pos > kMaxElems)
    {
    }
}

template <int len, int beg_pos>
const int NumSequence<len, beg_pos>::kMaxElems = 1024;

template <int len, int beg_pos>
NumSequence<len, beg_pos>::NumSequence(vector<int> *pe) : pelems_(pe)
{
}

#endif // __NUM_SEQUNCE_H__