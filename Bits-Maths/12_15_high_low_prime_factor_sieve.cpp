// Here we will find the highest and lowest prime factor of a number using sieve
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> hp(N);
vector<int> lp(N);
int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            // now for prime lp and hp are same
            lp[i] = hp[i] = i;
            // now if you have not used if condition and directly executed below for loop you have got divisore..
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
    int n = 6;
    cout << lp[n] << " " << hp[n];
    // now suppose you want to find prime factorization you can find easliy
    // As we know if we get any one prime factor using tht we can find all
    // here is how
    int num;
    cin >> num;
    vector<int> prime_factors;
    while (num > 1)
    {
        // int prime_factor = lp[num];
        int prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            num /= prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }

    for (auto value : prime_factors)
    {
        cout << value << " ";
    }
    return 0;
}
