#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n , int arr[]){
    /*
     Here we divide array in two part where starting part is sorted and last part is unsorted...So we pick element one by one 
     from unsorted part and put that in it's correct position in sorted part...
     Initially we assume only the first element to be sorted (arr[0]).
   */
    for (int i = 1; i < n; i++)
    {
        int target_element = arr[i]; // element to be put in it's correct position
        // If we are on ith index then the array from 0 to i-1 index will be sorted...
        // Now we will check from i-1 index till 0th till we find smaller element than our target_element
        // now suppose we find the smaller element on kth index so we will  shift element from k+1th index to ith index by one and then we will
        // place target_element on k+1th position
        int j = i - 1;
        
        for (; j >= 0; j--)
        {
            if (arr[j] > target_element)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = target_element;
    } 
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    // input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(n , arr);
    
    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}
/*
SPACE COMPLEXITY  - 0(1)
TIME COMPLEXITY - 0(n^2)
BEST TIME  - 0(n)   (if array s already sorted)
*/
// Insertion sort is in-pace and stable algorithm.
