#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = temp;
    }                                              
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}
/*
SPACE COMPLEXITY  - 0(1)
TIME COMPLEXITY - 0(n^2)
BEST TIME  - 0(n)
*/
// Insertion sort is in-pace and stable algorithm.
