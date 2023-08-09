#include <bits/stdc++.h>
using namespace std;
/*
Given a  number C ...you need to find two numbers A and B
where A xor with B give C such that product of A and B maximize...
constraints--->
1<=C<=1e5;
*/

/*
Now suppose any bit in C which is zero as we want to maximixe the product we will
always select that bit 1 for both A and B
now problem  is with the bit's that are set in C
there is catch in constraints as max values of  C is 1e5 there will be atmost 17 bits
now suppose all the bit's are set in C (worst case) there will be total of
2^17  diffrent cases...we can check each combination and maximize the product
more optimized approach we will discuss later first let's try this
*/
int main()
{
  int c;
  cin >> c;
  int bits = log2(c) + 1;
  int a = 0, b = 0;
  vector<int> set_bits_in_c;
  for (int i = 0; i < bits; i++)
  {
    if (c & (1 << i))
    {
      set_bits_in_c.push_back(i);
    }
    else
    {
      a |= (1 << i);
      b |= (1 << i);
    }
  }

  int sz = (1 << set_bits_in_c.size());
  long ans = INT_MIN;
  for (int i = 0; i < sz; i++)
  {
    int a_copy = a;
    int b_copy = b;
    for (int j = 0; j < set_bits_in_c.size(); j++)
    {
      if (i & (1 << j))
      {
        a_copy |= (1 << set_bits_in_c[j]);
      }
      else
      {
        b_copy |= (1 << set_bits_in_c[j]);
      }
    }
    long product = a_copy * 1LL * b_copy;
    ans = max(ans, product);
  }

  cout << ans;
  return 0;
}