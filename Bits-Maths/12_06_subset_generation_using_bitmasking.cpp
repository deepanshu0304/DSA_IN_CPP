#include <bits/stdc++.h>
using namespace std;

/*
Main idea is to represent subsets in form of binary
Given an array of length n we will assume a binary number of n bit
and whichever subset you are selecting we will set that index bit in binary number
suppose you have array [2,4,5] and you have selected [2,4]  we will set 0th and 1st bit
   011 will be corrosponding binary
*/
// complete code ..Actually it's a leetcode que so we are doing in same format
vector<vector<int>> subsets(vector<int> &nums)
{

    int n = nums.size();
    int subset_ct = (1 << n);
    vector<vector<int>> all_subsets;
    for (int i = 0; i < subset_ct; i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                subset.push_back(nums[j]);
            }
        }
        all_subsets.push_back(subset);
    }

    return all_subsets;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto subset_of_v = subsets(v);
    for (auto a : subset_of_v)
    {
        for (int b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Time complecity will be 0(n*2^n)
*/