#include <iostream>
using namespace std;

void printf(const char *s)
{
    while (*s)
    {
        if (*s == '%' && *(++s) != '%')
        {
            throw std::runtime_error("invalid format string: missing arguments");
        }
        cout << *s++;
    }
}
template <typename T, typename... Types>
// void printf(const char *s, const T &value, const Types &...args) // error: call of overloaded ‘printf(const char*&)’ is ambiguous
void printf(const char *s, const T &value, Types &...args)
{
    while (*s)
    {
        if (*s == '%' && *(++s) != '%')
        {
            cout << value;
            printf(++s, args...);
            return;
        }
        cout << *s++;
    }
    throw std::logic_error("extra arguments provide to print");
}

int main(int argc, char const *argv[])
{
    int* pi = new int;
    printf("%d %s hello!! %p %f\n", 15, "This is Ace", pi, 3.1415926);
    return 0;
}
