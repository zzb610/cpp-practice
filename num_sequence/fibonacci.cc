#include "fibonacci.h"
#include "num_sequence.h"

#include <vector>
using std::vector;

vector<int> Fibonacci::elems_;

int Fibonacci::Elem(int pos)
{
    if (!CheckIntegrity(pos, elems_.size()))
    {
        return 0;
    }
    if (pos > elems_.size())
    {
        Fibonacci::GenElems(pos);
    }
    return elems_[pos - 1];
}

ostream &Fibonacci::print(ostream &os) const
{
    int elem_pos = beg_pos_ - 1;
    int end_pos = elem_pos + length_;

    if (end_pos > elems_.size())
    {
        GenElems(end_pos);
    }
    while (elem_pos < end_pos)
    {
        os << elems_[elem_pos++] << ' ';
    }
    return os;
}

void Fibonacci::GenElems(int pos) const
{
    if (elems_.empty())
    {
        elems_.push_back(1);
        elems_.push_back(1);
    }

    if (elems_.size() <= pos)
    {
        int i = elems_.size();
        int n_2 = elems_[i - 2], n_1 = elems_[i - 1];
        for (; i < pos + 1; ++i)
        {
            int elem = n_2 + n_1;
            elems_.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}
