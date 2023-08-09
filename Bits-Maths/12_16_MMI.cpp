#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long fact[N];
// MMI ---> Modulo Multiplicative Inverse
/*
Fermet Theorem-->
A^(M-1) is congurent to 1*mod(M) where M is prime no and A is not multiple of M
it mean (A^(M-1))%M=1;
so (A^(M-2))%M=A^-1...which we want to find
*/
/*
(A/B)%M = ((A%M)*(B^-1%M))%M
B^-1%M is MMI of B
if (A*B)%M=1 it mean B is MMI of A....where B will lie between (1,M-1)
where A and M are co prime
*/
void factorial_calc(){
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (i * 1LL * fact[i - 1]) % M;
    }
}
int binExp(int a, int b, int m)
{
   
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1ll * a) % M;
        }
        b >>= 1;
        a = (a * 1ll * a) % M;
    }
    return result;
}

// now suppose you need to find aCb...way of selecting b items from a
// we will pre compute all the factorial

int main()
{
    factorial_calc();
    int a, b;
    cin >> a >> b;
    // we need to find  (a!/b!*(a-b)!)%M
    int num = fact[a] % M;
    int den = (fact[b] * 1ll * fact[a - b]) % M;
    int den_MMI = binExp(den, M - 2, M);
    //    cout<<den_MMI;
    int final_ans = (num * 1ll * den_MMI) % M;
    cout << final_ans;
    return 0;
}