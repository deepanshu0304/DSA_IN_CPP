#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    for (pair<int, int> value : v)
    {
        value.first++;
        cout << value.first << " " << value.second << endl;
        // upper line will print value after increased but it is not changed in v,,,,,
    }
    cout << endl;
    for (pair<int, int> value : v)
    {

        cout << value.first << " " << value.second << endl;
    }
    return 0;
} 