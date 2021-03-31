template <class T>
struct __list_node
{
    void *prev;
    void *next;
    T data;
};

template <class T, class Ref, class Ptr>
struct __list_iterator
{
    typedef _list_iterator<T, Ref, Ptr> self;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef __list_node<T> *link_type;

    link_type node;

    bool operator==(const self &x) const { return node == x.node; }
    bool operator!=(const self &x) const { return node != x.node; }

    reference operator*() const { return (*node).data; }
    pointer operator->() const { return &(operator*()); }
    self &operator++()
    {
        node = (link_type)((*node).next);
        return *this;
    }
    self operator++(int)
    {
        self tmp = *this;
        ++(*this);
        return tmp;
    }

    self& operator--()
    {
        node = (link_type) (*node).prev;
        return *this;
    }
    self operator--(int)
    {
        self tmp = *this;
        --(*this);
        return tmp;
    }
};

#include <iostream>

int main(int, char **)
{
    std::cout << "Hello, world!\n";
}
