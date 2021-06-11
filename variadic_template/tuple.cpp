template<typename... Values> class tuple;

template <>
class tuple<>
{
};

template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...>
{
    typedef tuple<Tail...> inherited;

public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

    // typename Head::type
    Head head()
    {
        return m_head;
    }
    inherited &tail()
    {
        return *this;
    }

protected:
    Head m_head;
};



#include <iostream>
#include <string>
// using namespace std; // 与标准库的tuple冲突
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    tuple<int, float, std::string> t(41, 6.3, "nico");
    cout << t.head() << endl;
    t.tail();
    cout << t.tail().head() << endl;

    return 0;
}
