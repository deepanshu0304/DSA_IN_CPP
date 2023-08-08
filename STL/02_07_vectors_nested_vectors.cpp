#include <bits/stdc++.h>
using namespace std;
void printvec(vector<int> v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.push_back(vector<int> ());/*
        in previous file we saw there should be smtg in it to access vector by index 
        so we inserted a empty vector in it so that we can acess directly
        .....generaly we not prefer this method ....but keep this in mind */
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
       
        
    }
    for (int k = 0; k < v.size(); k++)
    {
        printvec(v[k]);
    }
    // cout << v[2][2];
    return 0;
}
