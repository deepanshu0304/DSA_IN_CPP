#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  cout << __gcd(a, b) << endl;
  return 0;
}
// Approx time complexity of this function is log(n)....