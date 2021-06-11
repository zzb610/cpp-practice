#include <iostream>
using namespace std;

void print()
{

}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}



int main(int argc, char const *argv[])
{
    print("123",123,"hello");
    return 0;
}
