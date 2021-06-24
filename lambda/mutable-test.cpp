#include <iostream>

class Functor
{
private:
    int id; // copy outside id
public:
    Functor(int i) : id(i) {}
    void operator()()
    {
        std::cout << id << std::endl;
        ++id;
    }
};
int main(int argc, char const *argv[])
{
    int id = 0;

    auto f = [id]() mutable
    {
        std::cout << id << std::endl;
        ++id;
    };

    Functor f1(id);

    auto f3 = [&id]()
    {
        std::cout << id << std::endl;
        ++id;
    };

    // expression must be a modifiable lvalue
    // auto f4 = [id]()
    // {
    //     std::cout << id << std::endl;
    //     ++id;
    // };

    id = 42;
    f();                          // 0
    f();                          // 1
    f();                          // 2
    std::cout << id << std::endl; // 42
    f1();                         // 0
    f1();                         // 1
    f1();                         // 2
    std::cout << id << std::endl; // 42
    f3();                         // 42
    f3();                         // 43
    f3();                         // 44
    std::cout << id << std::endl; // 45
    return 0;
}
