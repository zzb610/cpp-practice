#include <iostream>
#include "triangular.h"
using namespace std;
int main(int, char **)
{
    Triangular tri(20);
    Triangular::iterator it = tri.begin();
    Triangular::iterator end_it = tri.end();

    cout << "Triangular Series of " << tri.length() << " elements\n";
    while (it != end_it)
    {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}
