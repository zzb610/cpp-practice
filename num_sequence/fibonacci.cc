#include "fibonacci.h"
#include "num_sequence.h"

#include <vector>
using std::vector;

vector<int> Fibonacci::elems_;
MEIvoid Fibonacci::GenElems(int pos) const
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
