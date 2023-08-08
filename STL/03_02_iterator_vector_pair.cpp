#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> v = {{10, 20}, {30, 40}, {50, 60}};

    vector<pair<int, int>>::iterator it = v.begin();

    /*
    Above line is syntax to declare  that it is iterator
    having name it and of type vector<pair<int, int>>
    It can be shortened by using auto keyword
    */
    cout << it->first << endl; // This is arrow operator which is short-hand for (*it).first;
    cout << ++it->second << endl;
    cout << (*++it).second << endl;
    for (it = v.begin(); it != v.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl; --> below written is more used syntax
        cout << it->first << " " << it->second << endl;
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        // cout << (*it).first << " " << (*it).second << endl; --> below written is more used syntax
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
