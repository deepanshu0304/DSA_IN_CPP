#include <bits/stdc++.h>
using namespace std;
/*
we can delete one edge from tree such that the product of sum of two subtree is maximum
*/
const int M = 1e9 + 7;
const int N = 1e3;
vector<vector<int>> tree(N);
int value[N];
vector<int> subtree_sum(N);

void dfs(int vertex, int parent = -1)
{
    subtree_sum[vertex] += value[vertex];
    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
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

    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        value[i] = x;
    }

        dfs(1);
        long long ans = 0;
        for (int i = 2; i <= n;i++){

        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - subtree_sum[i];

        ans = max(ans, ((part1 * 1ll * part2) % M));
        }
        cout << ans;
        return 0;
}