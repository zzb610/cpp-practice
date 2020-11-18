#include "tirangular_iterator.h"
#include "triangular.h"
#include <iterator>
bool TriangularIterator::operator==(const TriangularIterator &rhs) const
{
    return index_ == rhs.index_;
}
bool TriangularIterator::operator!=(const TriangularIterator &rhs) const
{
    return !(*this == rhs);
}
int TriangularIterator::operator*() const
{
    CheckIntegrity();
    return Triangular::elems_[index_];
}
TriangularIterator &TriangularIterator::operator++()
{
    ++index_;
    CheckIntegrity();
    return *this;
}
TriangularIterator TriangularIterator::operator++(int)
{
    TriangularIterator tmp = *this;
    ++index_;
    CheckIntegrity();
    return tmp;
}

#include <iostream>
void TriangularIterator::CheckIntegrity() const
{
    if (index_ >= Triangular::kMaxElems)
    {
        std::cerr << "iterator overflow" << std::endl;
        return;
    }
    if (index_ >= Triangular::elems_.size())
    {
        Triangular::GenElems(index_ + 1);
    }
}