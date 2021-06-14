#include <iostream>
using namespace std;
void func(int x)
{
    cout << "void func(int x)" << endl;
}

void func(void* px)
{
    cout << "void func(void* px)" << endl;
}

int main(int argc, char const *argv[])
{
    func(0); // void func(int x)
    // func(NULL); //  error: call of overloaded ‘func(NULL)’ is ambiguous
    func(nullptr); // void func(int x)
    return 0;
}
