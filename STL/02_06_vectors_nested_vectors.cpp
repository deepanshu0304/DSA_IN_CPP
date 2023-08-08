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
    int N;
    cin >> N;
    vector<vector<int>> v; /*
    in upper line only vector is created now you cn not directly access v[anything]..as it's not there...
    you need to push back something in vector to acees this type .
    if you define size of vector then you can access this type 
    if you not define vector size you can not use cin to take input also..
    */
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> temp; // why we need to create this.....
        // becoz in array of vector you can access one element which is vector and you can pushback element one by one
        // But in vectors of vectors you are not able to access one position of vector 
        // so you need to pushback whole vector in one go....
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            // v[i].push_back(x);
            temp.push_back(x);

        }
        // v[i] = temp;
       v.push_back(temp);
    }
    for (int k = 0; k < v.size(); k++)
    {
        printvec(v[k]);
    }
    cout << v[2][2];
    return 0;
}