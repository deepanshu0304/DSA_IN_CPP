#include <bits/stdc++.h>
using namespace std;
/*
Here we are finding (a^b)%M...
now suppose if a is already given very large like order of 10^18 or smtg like 2^1024
here how we will find it
(a^b) == a*a*a*a........*a  --> b times
we studied muodulo in multiply rule
(c*d)%M == ((c%M)*(d%M))%M
similarly
(a^b)%M == ((a%M)^b)%M
conclusion
If bigger value of a come we will convert it into modulo how
if coming like 10^18 order we will directly  do a%M
and if come smtg like 2^1024
then  we will find this in modulo by using our iterative method

*/
const int M = 1e9 + 7;
int bitExpIte(int a, int b)
{
    // if 10^18 .
    // a = a%M;
    // if 2^1024
    //  a= bitExpIte(2,1024);
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            // now if M is also large order of 10^18..you can not directly multiply it will overflow
            // you can do
            // ans = bitMulti(ans,a);
            ans = (ans * 1ll * a) % M;
        }
        // similarly
        // a = bitMulti(a,a);
        a = (a * 1ll * a) % M;
        b = b >> 1;
    }
    return ans;
}
long long bitMulti(long long a, long long b)
{

    int ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    int a = 2;
    int b = 10;
    int c = bitExpIte(2, 10);
    cout << c;
    return 0;
}
