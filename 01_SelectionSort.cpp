#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b) for(int i = a; i < b;i++)
const int M = 1e9+7;
const int N = 1e3+7;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1;i++){

        int min_index = i;
        for (int j = i+1; j < n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    return 0;
}