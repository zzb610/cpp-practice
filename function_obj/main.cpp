#include "less_than.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int count_less_than(const vector<int> &vec, int cmop)
{
    LessThan It(cmop);
    int count = 0;
    for (int v : vec)
    {
        if (It(v))
        {
            ++count;
        }
    }
    return count;
}

void print_less_than(const vector<int> &vec, int cmop, ostream &os = cout)
{
    LessThan It(cmop);

    vector<int>::const_iterator iter = vec.cbegin();
    vector<int>::const_iterator end_it = vec.cend();
    os << "elements less than " << It.ComVal() << endl;
    while ((iter = find_if(iter, end_it, It)) != end_it)
    {
        os << *iter << " ";
        ++iter;
    }
}
int main(int, char **)
{
    int ia[16] = {17, 12, 44, 9, 18, 45, 6, 14, 23, 67, 9, 0, 27, 55, 8, 16};
    vector<int> vec(ia, ia + 16);
    int comp_val = 20;
    cout << "Number if elements less than" << comp_val << " are " << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val);
}
