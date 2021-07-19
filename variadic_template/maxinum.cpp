#include <algorithm>
#include <iostream>
int maxinum(int n)
{
    return n;
}

template <typename T, typename... Args>
int maxinum(T value, Args... args)
{
    return std::max(value, maxinum(args...));
}

int main(int argc, char const *argv[])
{
    int res = maxinum(1, 3, 5, 7, 9, 99, 1);
    std::cout << res << std::endl;
    return 0;
}
