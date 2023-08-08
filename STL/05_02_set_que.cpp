#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string sr;
        cin >> sr;
        s.insert(sr);
    }
    for (string value : s)
    {
        cout << value << endl;
    }
    return 0;
}