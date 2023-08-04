#include <bits/stdc++.h>  // this header file contain all the in built data structure and algorithm.
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];

    // taking input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   
    for (int i = 1; i <= n-1; i++)
    {
        bool swapped = false; // we are maintaing this to check if there is any swap in current pass if there is no swap we can say
        //  our array is sorted
        for (int j = 0; j < n - i; j++)
        {
            // comparing two element if j+1 element is smaller we are swapping them....
            // so at the end of each pass the maximum element will be placed at their correct position
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}
/*
SPACE COMPLEXITY  - 0(1)
TIME COMPLEXITY - 0(n^2)
BEST CASE COMPLEXITY - 0(n)  (if array is already sorted).
*/

// Bubble sort is in-place algorithm 
// Bubble sort is stable sort.
