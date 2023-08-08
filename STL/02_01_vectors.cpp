#include <bits/stdc++.h>
using namespace std;
void printvec(vector<int>& v)
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x); // you can use directly cin here for vector but for that u need to declare the size of vector
        printvec(v);
    }
    /*now to print vector .....we will create afunction in which we will pass vector ..we will not pass size as in case of array
    because vector size is not fixed so there is predefined function by which we can access current size of vector*/
    return 0;
}

// both v.push_back and v.size().....both are of O(1) complexity....
// limits of vector is same as that of array