#include<bits/stdc++.h>
using namespace std;

int main(){
    // swapping of number...
    int a =45;
    int b = 56;
    a = a^b;
    b= a^b;
    a= a^b;
    cout<<a<<" "<<b<<endl;
    // swapping of number using arithmetic operation..
    a= a+b;
    b= a-b;
    a = a-b;
    cout<<a<<" "<<b<<endl;
/*
you are given an array in which all element have even frequency except one element
find that element in 0(N) complexity and 0(1) space...

ANS --->
you can not do it with hash table but space will be 0(N)...
 */
    return 0;
}