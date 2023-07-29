#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for (int i = a; i < b; i++)
const int M = 1e9 + 7;
const int N = 1e3 + 7;
/*
SPACE COMPLEXITY  - 0(n)
TIME COMPLEXITY - 0(nlog(n))

*/
void merge(int arr[], int s, int mid, int e)
{
      
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

    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


