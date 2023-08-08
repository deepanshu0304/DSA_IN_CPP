/*
A monk going in park ....park has n bags ...in each bag there are A[i] candies...
monk pick up bag and eat all candies in it when he puts bag down ....the bag get automaticaly filled 
by candies half of orginal....monk can eat a bag in one minute irrespective of candies...
monk has k minute to eat the candies....find the max no of canies that monk can eat
first line contain test case
next line contain n and k
next line contain a[i]...
constraints are ok no problem... */
#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<long int> s;
    int t;
    cin>>t;
    while(t--){
        int n,k,max_candy;
        cin>>n>>k;
        for(int i =0;i<n;i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        for(int j=1;j<=k;j++){
             auto last_it=s.end();
             last_it--;
            

             max_candy = max_candy +*(last_it);
             s.erase(last_it); // this is o(1) operation as you are erasing by use of iterator
             s.insert(*(last_it)/2);
        }
        cout<<max_candy;
    }
    return 0;
}