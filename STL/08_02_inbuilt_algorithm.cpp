#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int *max = max_element(a, a + n);
    cout << *max << endl;
    int *min = min_element(a, a + n);
    cout << *min << endl;
    int sum = accumulate(a, a + n, 0);
    cout << sum << endl;
    int ct = count(a, a + n, 2);
    cout << ct << endl;
    int *element = find(a, a + n, 2);
    cout << element << endl; // if element is not present it will return a+n....

    reverse(a, a + n); // this is the original array being reversed...and this function is very useful in cae of string
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

// All above mentioned function works in 0(n) complexity...
// count and find in case of maps and set are in log(n) operation....