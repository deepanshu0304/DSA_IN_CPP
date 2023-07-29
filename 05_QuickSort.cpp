#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for (int i = a; i < b; i++)
const int M = 1e9 + 7;
const int N = 1e3 + 7;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int ct = 0;
    rep(s + 1, e + 1)
    {
        if (arr[i] <= pivot)
        {
            ct++;
        }
    }
    int pivot_index = s + ct;
    swap(arr[s], arr[pivot_index]);
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
        else if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
    }
    return pivot_index;
}
void quickSort(int arr[], int s, int e)
{

    if (s >= e)
        return;
    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
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

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}