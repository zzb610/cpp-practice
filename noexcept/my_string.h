#ifndef MY_STRING_H
#define MY_STRING_H
#include <cstddef>
class MyString
{
private:
    char *_data;
    size_t _len;

public:
// 通知vector异构构造与析构不会抛出异常
// 在vector两倍增长的时候，对象的移动构造函数会被调用
    MyString(MyString &&str) noexcept
        : _data(str._data), _len(str._len)
    { /*...*/
    }
    MyString &operator=(MyString &&str) noexcept
    {
        /*...*/
        return *this;
    }
};

#endif /* MY_STRING_H */
