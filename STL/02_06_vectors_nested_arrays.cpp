#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v)
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
    // Array of vectors
    int N;
    cin >> N;
    vector<int> v[N]; // this mean every index of an array is a vector.
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        printvec(v[i]);
    }

    cout<<endl<<v[0][2]; /*Here v is array so v[0] will be a vector and in vector we can also access by index so v[0][2] will
                         print the third element of first vector. */

    return 0;
}
