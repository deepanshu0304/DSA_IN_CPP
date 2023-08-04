#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    //taking input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //1.) Here  in each pass we are picking minimum element from unsorted array and putting it  on it's correct position.
    //2.) we are using outer loop n-1 times only because after n-1 pass total of n-1 element will be in their correct position so automatically 
    // the last element will be sorted.

    // -- Time Complexity ---> 0(n^2)
    // -- Space Complexity ---> 0(1) no extra space used

    
    
    for (int i = 0; i < n-1;i++){

        int min_index = i;
        
        // inner loop for finding minimum from remaining unsorted element.
        for (int j = i+1; j < n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }

    
// printing the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    return 0;
}

    //!!! Selection Sort is not stable algorithm (stable mean if element are equal they should maintain their relative position in array)
    ///!!! Selection Sort is in-pace algorithm
