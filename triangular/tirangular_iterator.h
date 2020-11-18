#ifndef __TRIANGULARITERATOR__
#define __TRIANGULARITERATOR__

class TriangularIterator
{
public:
    TriangularIterator(int index) : index_(index - 1) {}
    bool operator==(const TriangularIterator &rhs) const;
    bool operator!=(const TriangularIterator &rhs) const;
    int operator*() const;
    TriangularIterator &operator++();
    TriangularIterator operator++(int);

private:
    void CheckIntegrity() const;
    int index_;
};

#endif // __TRIANGULARITERATOR__