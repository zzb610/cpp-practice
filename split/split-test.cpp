#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
void split(const string &str, vector<string> &svec, char delima = ' ')
{
    string::size_type pos = 0, prev_pos = 0;
    string::size_type str_size = str.size();
    while ((pos = str.find_first_of(delima, pos)) != string::npos)
    {
        string::size_type end_pos = pos - prev_pos;
        svec.push_back(str.substr(prev_pos, end_pos));
        ++pos;
        prev_pos = pos;
    }
    if (prev_pos < str_size)
    {
        svec.push_back(str.substr(prev_pos, pos - prev_pos));
    }
}

#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string str("hello word my zzb bbz zbzbzbz !");
    vector<string> svec;
    split(str, svec);
    for (auto s : svec)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
