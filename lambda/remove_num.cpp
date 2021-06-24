#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int x = 30;
    int y = 100;
    vector<int> vi{5, 28, 50, 83, 70, 590, 245, 59, 24};
    // 对于vector而言
    // remove_if的参数是迭代器，通过迭代器无法得到容器本身，而要删除容器内的元素只能通过容器的成员函数来进行，
    // 因此remove系列函数无法真正删除元素，只能把要删除的元素移到容器末尾并返回要被删除元素的迭代器，然后通过erase成员函数来真正删除。
    vi.erase(remove_if(vi.begin(), vi.end(), [x, y](int n)
                       { return x < n && n < y; }));
    for (const auto &i : vi)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
