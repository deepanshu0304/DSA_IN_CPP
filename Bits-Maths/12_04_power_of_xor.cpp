#include<bits/stdc++.h>
using namespace std;

int main(){
    // swapping of number..
// Its very common interview question...they ask to swap two numbers without using extra variables.....
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
Approach 1-->you can not do it with hash table but space will be 0(N)...

Approach 2---> Xor of same element is zero....and Xor of zero with any element is that element itself...
so if we xor all the elements is array so the elements with even frequency will make zero and one element with odd freq will be vakue stored in xor operation.
 */
    return 0;
}