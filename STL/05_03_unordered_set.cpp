/*
Difference between set and unordered set is same as difference in map and unordered map
time complexity will change from 0(logn) to 0(1)
inbuilt sorting will change
restriction on key datatype */

/*
in this file we have explained unodered set with help of question
given N strings and q queries ... for each query one string is given and we need to check wether that string is 
present or not*/
#include<bits/stdc++.h>
using namespace std;

int main(){

// unordered_set<string> s;
// s.insert("ac") ;   
// s.insert("adc")   ; 
// s.insert("acefw") ;   
// s.insert("acefrgv");    
// for(auto value : s){
//     cout<<value<<endl;
// }
int N;

cin>>N;
unordered_set<string> s;
for(int i =1;i<=N;i++){
    string str;
    cin>>str;
    s.insert(str);
}
int q;
cin>>q;
while(q--){
    string str;
    cin>>str;
    if(s.find(str)==s.end())
    cout<<"no\n";
    else
    cout<<"yes\n";
}
    return 0;
}