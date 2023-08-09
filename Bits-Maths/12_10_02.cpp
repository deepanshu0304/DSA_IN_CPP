/*
 Now suppose if b is given large ......
our code has no problem it is alright no matter how  big  value is b
problem willl come when  b will come like c^d
so overall (a^(c^d)) now here how we will apply modulation
here the concept come EFT----> Euler Totion Function
EFT for number n is count of k where 1<=k<=n
such that k and n are co prime number mean __gcd(k,n)=1
EFT is represented by fi(n)

now formula for finding etf of n is   n(capital pi((1-1/p)))...wehre p is all distnict prime factors of n
There is one syntax in math
a  equvivalent to b mod(n)
it mean when a is divided by n it give reminder as b...
now Euler theorem----
a^b =  (a^(b mod fi(n)))mod(n)....
some mathmatical operation
(a^b)%M =  ((a^(b%fi(M)))%M)   for any value of M
if M is prime
(a^b)%M =  ((a^(b%(M-1))%M
 below is code for it(whem M is prime)

*/

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int bitExpIte(int a, int b,int m)    // here we are also passing small m by which we need to find the modulo
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b = b >> 1;
    }
    return ans;
}
// suppose our que is 50^64^32
int main()
{
   
    int c = bitExpIte(50,bitExpIte(64,32,M-1),M );
    cout << c;
    return 0;
}
