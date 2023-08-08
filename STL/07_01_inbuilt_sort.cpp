// The inbuilt sort in c++ is best sorting algorithm...as it use introsort which is mixture of three sorting algorithm ....it take nlog(n) time complexity
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }  
    sort(a,a+n); // first one is from where to start sorting and second one is next adrress of where to stop sorting 
    for(int i =0;i<n;i++){
        cout<<a[i]<<" ";
    }  
    return 0;     
}