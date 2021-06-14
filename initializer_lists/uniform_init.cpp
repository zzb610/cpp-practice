#include <iostream>
#include <vector>
using namespace std;

#define VarName(var) #var

 
void print_name_value()
{
}

template <typename T, typename... Types>
void print_name_value(const T &first_arg, const Types &...args)
{
    cout << VarName(first_arg) << ":" << first_arg << endl;
    print_name_value(args...);
}

int main(int argc, char const *argv[])
{
    int i;
    int j{};
    int *p1;
    int *p2{};
    // i=22001(undefined) j=0
    cout << "i=" << i << " j=" << j << endl;
    // p1:nullptr p2:nullptr
    cout << "p1:" << ((p1 == nullptr) ? "nullptr" : "not null_ptr") << " p2:" << ((p2 == nullptr) ? "nullptr" : "not null_ptr") << endl;

    int x1(5.3);
    int x2 = 5.3;
    // int x3{5.3}; // error: narrowing conversion
    // int x4 = {5.3}; // error: narrowing conversion

    char c1{13};
    // char c2{99999}; //  error: narrowing conversion

    vector<int> v1{1, 2, 4, 5};
    // vector<int> v2{1, 2.3, 4, 5.6};//error: narrowing conversion of

    print_name_value(x1, x2, c1);
    print_name_value(c1);
    return 0;
}
