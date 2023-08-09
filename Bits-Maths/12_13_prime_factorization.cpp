#include <bits/stdc++.h>
using namespace std;

int main()
{
    // prime factor code
    int n;
    cin >> n;
    vector<int> v;
    // for(int i =2;i<=n;i++){
    //      while(n%i==0){
    //         v.push_back(i);
    //         n/=i;
    //      }
    // }

    for (int i = 2; i * i <= n; i++)
    {

        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        v.push_back(n);
        
    for (auto a : v)
    {
        cout << a << " ";
    }
    return 0;
}
/*
Again we will try to reduce the time we can run it till sqrt(n) but there will be slight problem
when the last prime number will left alone  suppose 2^x*5^1...anything condition is last prime factor have power 1
so we just need to add one more cond

*/