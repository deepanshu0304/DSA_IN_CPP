#include <bits/stdc++.h>
using namespace std;


int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    // selected the pivot as our first element
    int ct = 0;
    // we will count the smaller element than our pivot
    for( int i =s + 1, i<=e ; i++)
    {
        if (arr[i] <= pivot)
        {
            ct++;
        }
    }
    // now there are ct elements that are smaller than our pivot so the correct place for pivot is s+ct
    int pivot_index = s + ct;
    swap(arr[s], arr[pivot_index]); // so our pivot element is placed on it's correct position
    // now the remaining task is to place all the element smaller than pivot to its's left anf greater element to right of pivot_index

    /* we will declare two variable one will be pointing to start of array (s) say i and one will point to end of array (e) say j
    now we will increment i till we get element greater than pivot and we will decrement j till we get element smaller than pivot
    now as ith element is greater than pivot and jth element is smaller than pivot so we will swap them  to achieve our target
    we will repeat this until all the smaller element are on the left of pivot_index and all the larger element are on the right side 
    of pivot_index
    */
    int i = s;
    int j = e;
    while (i < pivot_index && j > pivot_index)
    {
        if (arr[i] > pivot && arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        while (arr[i] <= pivot)
        {
            i++;
        }
       while (arr[j] > pivot)
        {
            j--;
        }
    }
    // at first so think there is loop inside loop so the complexity will be more but if you carefullt observe it ...it is only o(n)
    return pivot_index; // return pivot_index as all smaller element are on left and larger on right // so we will call sam function for left and right subarray 
}
void quickSort(int arr[], int s, int e)
{

    if (s >= e)
        return;
    int p = partition(arr, s, e); // pth element is placed in correct position and all the element on left are smaller and all element on
    // right are greater which we can view as two subProblem so we recursively call quickSort for left subarray and right subArray
    // (remember we need to solve one case remaining recursion will do)

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
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

    /* Here the idea is to pick an element an put it on it's correct position and all the element on left side of it should be smaller and
     all element on right side should be greater than picked element

     There are mainly three ways to pick  element
     1) always pick first element
     2.) always pick middle element
     3.) always pick last element 
     In this code we have picked first element
     
     */
    

    quickSort(arr, 0, n - 1); // dry run this complete function 4-5 times you will surely understand (basic recursion is needed)
    
    // printing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
TIME COMPLEXITY - 0(nlogn)
WORST CASE - 0(n^2)  (if array is already sorted)
SPACE COMPLEXITY  - 0(1)  as no extra space is used  but there will be space used by recursion stack space which will be o(n) in worst case
*/

//!! Quick sort is not stable algorithm and is in-pace algorithm

