#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v = {1,2,3,4,5};
    for (int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> :: iterator it = v.begin() ;
    cout<<*it<<endl;
    cout<<*(it+1)<<endl; // down two method are also correct way of rwritin
    // cout<<*(++it)<<endl;
    // cout<<*++it<<endl;
    for(it=v.begin(); it !=v.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}