#include<bits/stdc++.h>
using namespace std;
// best code for decimal to binary...and you can print as much bits you want ....
void printbinary(int n){
    for(int i=30;i>=0;i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}

int main(){
    int a=INT_MAX;
    // cout << (a >> 1) << endl;
    // cout << (1 << 0) << endl;
    printbinary(a);
    // To find if bit is set or not.....
    if(((1<<2)&a) !=0){
        cout<<"Bit is Set"<<endl;
    }
    else{
        cout<<"Bit is not set"<<endl;
    }

    // bit set...
    printbinary(a | (1<<2));

    // bit unset...
    printbinary(a&(~(1<<3)));
    // toggle bit...
    printbinary(a^(1<<0));
    
    // count no of set bits...
    int ct=0;
    for(int i =30;i>=0;i--){
        if(((1<<i)&a) !=0){
        ct++;
    }
    }
    cout<<ct<<endl;
    // There is internal function to count set bit..
    cout<<__builtin_popcount(a)<<endl; // this will not work for long integers...that have diff functions
    cout<<__builtin_popcountll((1LL<<35))<<endl;
    cout<<__builtin_popcountll((1LL<<35)-1)<<endl;
    /*__builtin_popcount function have time complexity log(n).....but actually it happen 
    so fast we count it's time complexity as 0(1) only
    */

    return 0;
}