#include <bits/stdc++.h>
using namespace std;
/*
Here we will write code for dfs in tree
we can do some optimisation
we do not need any visited arrray now because there is no loop
and it should not go backward that we can control by passing the parent
*/
const int N = 1e3;
vector<vector<int>> tree;
vector<int> depth(N);
vector<int> height(N);
void dfs(int vertex, int parent)
{

    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    dfs(1, 0);  // either pass 0 here or you can set a default value in dfs function 
    return 0;
}