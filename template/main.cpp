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

    pair() : fisrt(T1()), second(T2()) {}
    pair(const T1 &a, const T2 &b) : fisrt(a), second(b) {}

    template <class U1, class U2>
    pair(const pair<U1, U2> &p) : fisrt(p.fisrt), second(p.second) {}
};

// // shared_ptr
// template <typename _Tp>
// class shared_ptr
// {
//     template <typename _Tp1>
//     explicit shared_ptr(_Tp1 *__p) : __shared_ptr<_Tp>(__p) {}
// };

// template specialization
namespace zzb
{
    template <typename T>
    struct hash
    {
    };

    template <>
    struct hash<char>
    {
        size_t operator()(char x) const
        {
            return x;
        }
    };

    template <>
    struct hash<int>
    {
        size_t operator()(int x) const
        {
            return x;
        }
    };
}

// partial specialization

// number partial
namespace zzb
{
    template <typename T, typename Alloc>
    class vector
    {
    };

    template <typename Alloc>
    class vector<int, Alloc>
    {
    };
}
// range partial
template <typename T>
class C
{
};

template <typename T>
class C<T *>
{
};

// template template parameter
namespace zzb
{
    // template <typename T, template <typename T> class Container>
    // class XCls
    // {
    // private:
    //     Container c;
    // };

    template <typename T, template <typename U> class SmartPtr>
    class XCls
    {
    public:
        XCls() : sp(new T) {}

    private:
        SmartPtr<T> sp;
    };
}

#include <deque>
// this is NOT template template parameter
namespace zzb
{
    using std::deque;
    template<typename T, class Sequece=deque<T>>
    class stack
    {
        friend bool operator==(const stack&, const stack&);
        friend bool operator<(const stack&, const stack&);

        protected:
            Sequece c;
    };
}


class Base1;
class Derived1;
using namespace std;
#include <string>
#include <memory>
#include <list>
int main(int, char **)
{

    // Base1* ptr = new Derived1; // up-cast
    // shared_ptr<Base1> sptr(new Derived1); // up-cast like
    // std::cout << "Hello, world!\n";

    // cout << zzb::hash<int>()(1000) << endl;
    // zzb::XCls<string, shared_ptr> p1;
    zzb::stack<int> s1;
    zzb::stack<int, list<int>> s2;
}
