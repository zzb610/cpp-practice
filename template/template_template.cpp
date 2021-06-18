#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define SIZE 10
template <typename T, template <class> class Container>
class XCls
{
private:
    Container<T> c;

public:
    XCls()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            c.insert(c.end(), T());
            cout << c.size() << endl;
        }
        Container<T> c1;
        Container<T> c2(std::move(c1));
        c1.swap(c2);
    }
};

template <typename T>
using Vec = vector<T, allocator<T>>;

int main(int argc, char const *argv[])
{
    XCls<string, Vec> c1;
    return 0;
}
