// ....you can do it with simple function as well but we will do all thing here with lambda function 
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v ={2,3,4,5};
    cout<<all_of(v.begin(),v.end(), [](int x){return x>0;})<<endl; // will return true if all element satisfy that condition
    cout<<any_of(v.begin(),v.end(), [](int x){return x>0;})<<endl; // will return true if any of element satisfy that condition
    cout<<none_of(v.begin(),v.end(), [](int x){return x>0;})<<endl; // will return true if all of element do not satisfy that condition
    cout << none_of(v.begin(), v.end(), [](int x){ return x ==2; }) << endl;

    return 0;
}