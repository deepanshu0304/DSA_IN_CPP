#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int , string> m;
    m[1] = "asd";
    m[2] = "weq";
    m[5]= "zcz";
    m[3]= "def";
 // find function will return iterator of that value....u need to input a key if that key is not present it will return iterator of m.end
    auto it = m.find(7);// Time complexity of m.find is 0(log(n))......
    if(it==m.end()){
        cout<<"No Value";
    }
    else
    cout<<it->second<<endl;
    
}