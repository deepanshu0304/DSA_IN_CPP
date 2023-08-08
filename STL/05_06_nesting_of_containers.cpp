#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<string, string>, vector<int>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int s;
        cin >> fn >> ln >> s;

        for (int j = 0; j < s; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    for (auto &abc : m)
    {
        auto &pr = abc.first;
        auto &vec = abc.second;
        cout << pr.first << " " << pr.second << " " << vec.size() << endl;
        for (auto &list : vec)
        {
            cout << list << " ";
        }
        cout << endl;
    }

   /* for (auto &abc : m)
    {
        cout << abc.first.first << " " << abc.first.second << " " << abc.second.size() << endl;


        for (int i = 0; i < abc.second.size(); i++)
        {
            cout << abc.second[i] << " ";
        }


        // for (auto &list : abc.second)
        // {
        //     cout << list << " ";
        // }


        cout << endl;
    }
    */
    return 0;
}