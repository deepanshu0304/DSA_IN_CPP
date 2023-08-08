// Set is somewhat similar to maps.....
#include<bits/stdc++.h>
using namespace std;
void print(set<string> &s){
    for(auto value : s){
        cout<<value<<endl;
    }
}
int main(){
    set<string> s;
    s.insert("abc");   // Time complexity is log(n)
    s.insert("df");
    s.insert("ijk");

    // now here also all that function work in same way .....

    // auto it = s.find("abc");  --> log(n)
    // if(it != s.end){
    // s.erase(it);
    // }
    s.erase("def");
    print(s);
    

    return 0;
}
// Accessing the set is also of time complexity log(n).....