#include <bits/stdc++.h>
using namespace std;
/*
Given an array of N length and given q queries in each query given one integer x
now you can select any one number from array and can divide the x any time by the number selected from array
(possibly zero time )  such that the resulting number you can write as product of
exactly two prime number they can be same and dffrent also..
constraints---->
N<=1e5                                                 
A[i],Q,X<=1e6
*/

/*
Here is the concept...
we will find the prime factor of given X pair wise pair we will select two of it's
prime factor and divide by them and then our target will be to find the resulting
number in an array or any number in array whose any power can result in this resulting
number

we will break this que in part


first part is to find the prime factors of given number here we will do a trick
we will find only distinct prime number i will tell you why
 when we find prime numbers to select it pair wise pair we need b^2 complexity
where b is total no of prime factor now inside query loop when you use b^2 loop
it will exceed time ...so if we find distinct prime factor here you will say we will miss one
case when the prime number is same .....what we will do is to check if a particular prime
number has occured  2 time inside query loop itself


second part is to check whether the resulting number is present in array or any number
present in array whose power is resultiing number
how we will do that ...using sieve technique and hsh array
*/
vector<int> prime_factor(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
            x /= pf;
        ans.push_back(pf);
    }
    return ans;
}
const int N = 1e6 + 10;
int hp[N];
int hsh[N];
vector<int> can_be_removed(N);
int main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        hsh[a]++;
    }
    can_be_removed[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (hsh[i])
        {
            for (long long j = i; j < N; j *= i)
            {
                can_be_removed[j] = 1;
            }
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        bool ans = false;
        vector<int> pf = prime_factor(x);
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];
                if (x % product != 0)
                    continue;
                int num_to_be_removed = x / product;
                if (can_be_removed[num_to_be_removed])
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
                break;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}