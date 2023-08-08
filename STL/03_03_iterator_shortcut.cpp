#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    {
        for (int value : v)
        {
            value++;
            // cout<<value<<" ";
        }
        for (int value : v)
        // will print the same vector as in upper for loop you only passed copy
        {

            cout << value << " ";
        }
    }
    cout << endl;
    for (int &value : v)
    {
        value++;
    }

    for (int value : v)
    {
        cout << value << " ";
    }

    return 0;
}