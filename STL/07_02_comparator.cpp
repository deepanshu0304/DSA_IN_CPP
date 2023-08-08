/*
whenever you write any sorting algorithm  there is always use of one function 
 swap .....we apply some condition  and if that's true than swap
 .... so simply we can pass that condition and it will sort according to that..*/
#include<bits/stdc++.h>
const int N = 1e5;
int hsh[N];
using namespace std;
   bool cmp( int a ,  int b){
    
    return a== b;

   } 
int main(){

    int n;
    cin>>n;
    vector <int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
        hsh[v[i]]++;
    }
    int count =0;
    for(int i =0;i<N;i++){
        if(hsh[i] != 0)
         count++;

    }
    for(int i =1;i<=count;i++){
    sort(v.begin() ,  v.end() , cmp); 
    } // if you pass false then  it will swap the function  
    for(int i =0;i<n;i++){
        cout<<v[i]<<" ";
    }



    
    return 0;
}

/*
by default the sorting behaviour is  increasing order 
you can alter that by using compraator functon ....
again  there are some inbuilt comparator function which can be used...*/