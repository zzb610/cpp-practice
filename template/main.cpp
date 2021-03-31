#include <iostream>

// class template
template <class T>
class complex
{
};

// function template
template <class T>
const T &min(const T &a, const T &b)
{
    return b < a ? a : b;
}

// member template

// pair
template <class T1, class T2>
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 fisrt;
    T2 second;

    pair() : fisrt(T1()), second(T2()){}
    pair(const T1& a, const T2&b): fisrt(a), second(n){}

    template<class U1, class U2>
    pair(const pair<U1, U2>& p): fisrt(p.fisrt), second(p.second){}
};

// shared_ptr
template<typename _Tp>
class shared_ptr
{
    template<typename _Tp1>
    explicit shared_ptr(_Tp1* __p): __shared_ptr<_Tp>(__p){}
};

class Base1;
class Derived1;
int main(int, char **)
{

    Base1* ptr = new Derived1; // up-cast
    shared_ptr<Base1> sptr(new Derived1); // up-cast like
    std::cout << "Hello, world!\n";
}
