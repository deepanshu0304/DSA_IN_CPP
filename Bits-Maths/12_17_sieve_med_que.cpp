#include <bits/stdc++.h>
using namespace std;
/*  
given an array A of length N in whcih T queries are asked in each query given
P and Q you need to find the count of number in array  that are multiple of a or b or both
constraint s--->
N,A[i],P,Q,T<=2*1e5
*/
// Brute force you will travers the array and will find the count ..but it will exceed time
// so what can be done is pre computation...
/*
Here we know max value of p and q is given also a[i] max value we know
what we will do is we will count the frequency of the number in array
using which we will find the total no of multiple of each number from 1 to 2*1e5 in array
how??
by using sieve....
we will construct an array whose ith index will store the multiple of i in given array
*/
const int N = 2e5 + 10;
int hsh[N];
int multiple_ct[N];

int main()
{
    int n;
    cin >> n;
    // int a[n];
    for (int i = 0; i < n; i++)
    {
        // cin>>a[i];
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            multiple_ct[i] += hsh[j];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        int ans = multiple_ct[p] + multiple_ct[q];
        long long lcm = (p * 1ll * q) / __gcd(p, q);
        if (lcm < N)
            ans -= multiple_ct[lcm];
        cout << ans << endl;
    }
    return 0;
}