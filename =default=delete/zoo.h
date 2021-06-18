#ifndef ZOO_H
#define ZOO_H

class Zoo
{
public:
    // ctor
    Zoo(int i1, int i2) : d1(i1), d2(i2) {}
    // copy ctor
    Zoo(const Zoo &) = delete;
    // move ctor
    Zoo(Zoo &&) = default;
    // copy =
    Zoo &operator=(const Zoo &) = default;
    // move =
    Zoo &operator=(const Zoo &&) = delete;
    // dtor
    virtual ~Zoo() = default;

private:
    int d1, d2;
};

// #include <memory>

// int main(int argc, char const *argv[])
// {
//     std::unique_ptr    
//     return 0;
// }

#endif /* ZOO_H */
