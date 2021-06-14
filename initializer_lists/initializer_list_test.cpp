#include <iostream>
using namespace std;
class P
{
public:
    P(int a, int b)
    {
        cout << "P(int a, int b)"
             << " a=" << a << "b=" << b << endl;
    }
    P(initializer_list<int> initlist)
    {
        cout << "P(initializer_list<int> initlist)"
             << "values:";
        for (const auto &i : initlist)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{

    P p(77, 5);
    P q{77, 5};
    P r{77, 5, 42};
    P s = {77, 5};
    return 0;
}
