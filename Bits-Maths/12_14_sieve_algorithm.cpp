#include <bits/stdc++.h>
using namespace std;
/*
  we know one mehtod to find prime number but suppose we need to find big prime number also many
  like given q queries and in each query asked to find wether the number is prime or not
  we use sieve theorem for it ......very important not only in this but it's variation also used frequently
  now suppose there are Q queries and each query contain integer N
  constraints----
  Q<=10^7
  N<=10^7

*/
// now what we will do is we will precompute all the prime numbers till 10^7
const int N = 1e7+10;
vector<bool> isPrime(N, 1);
int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i =2;i<N;i++){
        if(isPrime[i]==true){
            for(int j = 2*i;j<N;j+=i){
                isPrime[j]=false;
            }
        }
    }
/*
time complexity for upper loop let's calculate
suppose there is no if statement
then time complexity will be    
n/2 + n/3 + n/4 + n/5 + n/6 +........ which is approx nlog(n)
but we have much less then this as loop is not always working
 which will be (we will not go through mathematics)
 nlog(log(n))

*/
   
   int q;
   cin>>q;
   while(q--){
    int num;cin>>num;
    if(isPrime[num]){
        cout<<"Prime"<<endl;
    }
    else cout<<"Not Prime"<<endl;
   }

    
    return 0;
}