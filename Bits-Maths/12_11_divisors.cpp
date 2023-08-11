#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    //naive way of finding divisors
  /*  int ct=0;
    int sum =0; // sum of all divisiors.
    for(int i =1;i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            ct++;
            sum+=i;
        }
    }
    cout<<ct<<" "<<sum<<endl;
    */
// Lower method is better than upper but still we need more optimized approach.

   int ct=0;
   int sum =0;
   for(int i =1;i*i<=n;i++){
    if(n%i==0){
        cout<<i<<" "<<n/i<<endl;
        ct++;
        sum+=i;
        if(n/i !=i){
            ct++;
            sum+=n/i;
        }
    }
   }
   cout<<ct<<" "<<sum<<endl;
    return 0;
}