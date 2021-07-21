// composed tupe

#include <iostream>
#include <string>
using std::cout;
using std::endl;


template <typename... Values>
class tup;

template<>
class tup<>
{

};

template <typename Head, typename... Tail>
class tup<Head, Tail...>
{
    typedef tup<Tail...> composed;

public:
    tup(){};
    tup(Head v, Tail... tail) : m_head(v), m_tail(tail...) {}

    Head head() { return m_head; }
    composed &tail() { return m_tail; }

protected:
    Head m_head;
    composed m_tail;
};



int main(int argc, char const *argv[])
{
    tup<int, float, std::string> t(41, 6.3, "nico");
    cout << t.head() << endl;
    t.tail();
    cout << t.tail().head() << endl;
    cout << t.tail().tail().head() << endl;


    return 0;
}