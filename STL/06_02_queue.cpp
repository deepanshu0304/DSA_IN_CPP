#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;
    q.push("abcd");
    q.push("bbc");
    q.push("vfgd");
    q.push("dwer");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}