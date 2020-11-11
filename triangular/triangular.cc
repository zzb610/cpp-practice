#include "triangular.h"
#include <algorithm>
#include <iostream>

using std::vector;
const int Triangular::kMaxElems = 1024;
vector<int> Triangular::elems_;

Triangular::Triangular(int length, int beg_pos) : length_(length), beg_pos_(beg_pos), next_(beg_pos - 1), name_("Triangular")
{
    int elem_cnt = beg_pos + length - 1;
    if (elems_.size() < elem_cnt)
    {
        GenElems(elem_cnt);
    }
}

Triangular::Triangular(const Triangular &rhs) : length_(rhs.length_), beg_pos_(rhs.beg_pos_), next_(rhs.next_), name_(rhs.name_) {}

int Triangular::elem(int pos) const
{
    return elems_[pos - 1];
}

bool Triangular::next(int &val) const
{
    if (next_ < beg_pos_ + length_ - 1)
    {
        val = elems_[next_++];
        return true;
    }
    return false;
}

Triangular &Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs)
    {

        length_ = rhs.length_;
        beg_pos_ = rhs.beg_pos_;
        next_ = rhs.beg_pos_ - 1;
    }
    return *this;
}
int sum(const Triangular &trian)
{
    if (!trian.length())
    {
        return 0;
    }
    int val, sum = 0;
    while (trian.next(val))
    {
        sum += val;
    }
    return sum;
}

bool Triangular::IsElem(int value)
{
    if (!elems_.size() || elems_[elems_.size() - 1] < value)
    {
        GenElemsToValue(value);
    }
    vector<int>::const_iterator found_it = std::find(elems_.cbegin(), elems_.cend(), value);
    return found_it == elems_.cend();
}
void Triangular::GenElems(int length)
{
    if (length < 0 || length > Triangular::kMaxElems)
    {
        std::cerr << "illeage length" << std::endl;
        return;
    }
    if (elems_.size() < length)
    {
        int ix = elems_.size() ? elems_.size() + 1 : 1;
        for (; ix < length + 1; ++ix)
        {
            elems_.push_back(ix * (ix + 1) / 2);
        }
    }
}
void Triangular::GenElemsToValue(int value)
{
    int ix = elems_.size();
    if (!ix)
    {
        elems_.push_back(1);
        ix = 1;
    }
    while (elems_[ix - 1] < value && ix < kMaxElems)
    {
        ++ix;
        elems_.push_back(ix * (ix + 1) / 2);
    }

    if (ix == kMaxElems)
    {
        std::cerr << "Triangular Sequence: oops: value too large" << value << "-- exceeds max size of" << kMaxElems << std::endl;
    }
}
void Triangular::display(int length, int beg_pos, ostream &os)
{
    TriangularIterator first(beg_pos);
    TriangularIterator last(beg_pos + length);
    for (; first != last; ++first)
    {
        std::cout << *first << " ";
    }
    cout << std::endl;
}

ostream &operator<<(ostream &os, const Triangular &rhs)
{
    os << "(" << rhs.beg_pos() << "," << rhs.length() << ")";
    rhs.display(rhs.length(), rhs.beg_pos(), os);
    return os;
}
istream &operator>>(istream &is, Triangular &rhs)
{
    char ch1, ch2;
    int bp, len;
    is >> ch1 >> bp >> ch2 >> len;
    rhs.beg_pos(bp);
    rhs.length(len);
    rhs.NextReset();

    return is;
}