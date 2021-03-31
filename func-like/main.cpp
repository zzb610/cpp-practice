template <class T>
struct my_plus
{
    T operator()(const T &x, const T &y)
    {
        return x + y;
    }
};

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    my_plus<int> plus_func;
    cout << plus_func(1, 2) << endl;
    return 0;
}
