#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<vector<int>> tree(N);
int par[N];

void dfs(int vertex, int parent = -1)
{
    par[vertex] = parent;
    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex);
    }
}

vector<int> path(int v)
{
    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    dfs(1);
    int a, b;
    int lcs_of_a_and_b;
    cin >> a >> b;
    vector<int> path_of_a = path(a);
    vector<int> path_of_b = path(b);

    int mn_ln = min(path_of_a.size(), path_of_b.size());

    for (int i = 0; i < mn_ln; i++)
    {

        if (path_of_a[i] == path_of_b[i])
        {
            lcs_of_a_and_b = path_of_a[i];
        }
        else break;
    }
    cout << lcs_of_a_and_b;
    return 0;
}