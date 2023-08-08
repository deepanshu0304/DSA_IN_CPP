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
     printvec(v);      // In function  we added a line which is pushing an element in vector...
     printvec(v);    // As the vector was passed by reference the value added in prev func will reflect here.
     printvec(v2);   // V2 is also reference of V so the same changes will also appear in V2.
    

    return 0;
}
