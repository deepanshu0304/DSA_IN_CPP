#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
      // merge two sorted array we already say in previous file .... 
      // so here our two sorted array are one from s to mid and second from mid+1 to e...now we will copy these two array in two seprate new array
      // then we apply the concept discussed in previous file and store the result in main array.
    int leftlen = mid - s + 1;
    int rightlen = e - mid;
    int leftarr[leftlen]; 
    int rightarr[rightlen];
    for (int i = 0; i < leftlen; i++)
    {
        leftarr[i] = arr[s + i];
    }
    for (int i = 0; i < rightlen; i++)
    {
        rightarr[i] = arr[mid + 1+i ];
    }

    int index0 = 0;
    int index1 = 0;
    int mainIndex = s;
    while (index0 < leftlen && index1 < rightlen)
    {
        if (leftarr[index0] <= rightarr[index1])
        {
            arr[mainIndex] = leftarr[index0];
            index0++;
        }
        else
        {
            arr[mainIndex] = rightarr[index1];
            index1++;
        }
        mainIndex++;
    }

    while (index0 < leftlen)
    {
        arr[mainIndex++] = leftarr[index0++];
    }
    while (index1 < rightlen)
    {
        arr[mainIndex++] = rightarr[index1++];
    }
}

void mergeSort(int arr[], int s, int e)
{

    if (s >= e)  // base case when size become 1 or less
        return;

    int mid = s + (e - s) / 2; // finding mid of array ... now our array will be parted in two ways one from start to  mid and one from mid+1 to end
    mergeSort(arr, s, mid); // recursively calling the same function for left subarray
    mergeSort(arr, mid + 1, e); // recursively calling the same function for right subarray
    merge(arr, s, mid, e);   // merging left and right subarray (left and right subarray are sorted)
      // If you dont know recursion it will be difficult for you to understand
      //!! One tip for recursion questions "Just focus on one case (or one subproblem) recursion will take care for remainig case"   
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
      /*
      Merge sort is divide and conquer technique.Here we divide array into two parts continoulsy..and when the size become 1 we stop
      Now if there is one element in array it will always be sorted now we will use merge two sorted array (discussed in previous file)
      (bit difficult to understand i will suggest to take one random array and try to dry run it step by step written in this file , 
      i have written what each line is doing)
      */
    mergeSort(arr, 0, n - 1);

      // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
SPACE COMPLEXITY  - 0(n)
TIME COMPLEXITY - 0(nlog(n))
*/
// Merge sort is stable algorithm .
// As it use extra space so it's not in-place algorithm.

