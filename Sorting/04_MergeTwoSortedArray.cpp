#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSortedArray(int n1, int arr1[], int n2, int arr2[])
{

    // this is the most efficient approach two merge two sorted array in sorted manner
    /*
    As we already know both the array is sorted so we will compre their 0th index whichever is the smaller
    will be the smallest of all n1+n2 elements ... so we will put that first..and we will increase the
    corresponding index..we will continue this until we put all the element

    */
    vector<int> ans(n1 + n2);
    int i = 0; // for arr1
    int j = 0; // for arr2
    int mainIndex = 0;
    while (i < n1 && j < n2)
    {
        // if arr1 element is smaller we will take that and increase it's index;
        if (arr1[i] < arr2[j])
        {
            ans[mainIndex] = arr1[i];
            i++;
            mainIndex++;
        }
        // else we are taking element from arr2 and will increase arr2 index for next comparison
        else
        {
            ans[mainIndex] = arr2[j];
            j++;
        }
    }

    // we are not sure if their sizes are same they can be different so what if n1 has still element left
    // and arr2 is already done....so we will put remaining element from arr1 one by one as they
    // are already sorted
    while (i < n1)
    {
        ans[mainIndex] = arr1[i];
        i++;
        mainIndex++;
    }

    // same what if there are element remaining in arr2
    while (j < n2)
    {
        ans[mainIndex] = arr2[j];
        j++;
        mainIndex++;
    }

    // out of these two while loop one will be executed
}

int main()
{

    int n1, n2;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    // given array will  be sorted ... we need to merge them such that the resultant array should also be sorted
    vector<int> mergedArray = mergeTwoSortedArray(n1, arr1, n2, arr2);

    // printing array
    int sz = mergedArray.size();
    for (int i = 0; i < sz; i++)
    {
        cout << mergedArray[i] << " ";
    }

    return 0;
}

/*
Space Complexity - 0(1)
Time Complexity - 0(n1+n2)
*/
