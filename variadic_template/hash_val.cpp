// 标准库中variadic template的应用
#include <cstddef>
#include <functional>
#include <iostream>

using namespace std;

template <typename T>
inline void hash_combine(size_t &seed, const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T>
inline void hash_val(size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(size_t &seed, const T &val, const Types &...args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types &...args)
{
    size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

int main(int argc, char const *argv[])
{
    const char* s = "123";
    int i = 10;
    float f = 1.1;
    // 不能是右值
    cout << hash_val(s,i,f) << endl;
    return 0;
}
