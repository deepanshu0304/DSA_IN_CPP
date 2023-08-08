#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v) // if refrence is passed
{
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    v.push_back(2);
}
int main()
{

    vector<int> v;
    v.push_back(7);
    v.push_back(6);

    // vector<int> v2 = v; 
     vector<int> &v2= v;
  
     v2.push_back(5);  // as you passed refrence now the changes in v2 will also reflect in v....
     printvec(v);   // in this the changes is function happenend and in down line it will reflect in output
     printvec(v);   
     printvec(v2);   // also changes in v will reflect in v2
    

    return 0;
}
