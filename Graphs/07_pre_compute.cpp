#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<vector<int>> tree(N);
vector<int> subtree_sum(N); // store the subtree_sum
vector<int> even_ct(N);     // store the number of even vertex in it's subtree

void dfs(int vertex, int parent)
{

    if(vertex%2==0){
        even_ct[vertex]++;
    }
    subtree_sum[vertex] = vertex;
    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;
            
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];
    }
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    dfs(1, 0);

    for (int i = 1; i < n;i++){
        cout << subtree_sum[i] << " ";
    }
        return 0;
}