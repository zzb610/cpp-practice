#include <iostream>

template<class T>
class shared_ptr
{
public:
    T& operator*() const
    {
        return *px;
    }
    T* operator->() const
    {
        // -> opeator result will be passed to px
        return px;
    }
private:
    T* px;
    long* pn;
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
