#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<vector<int>> tree(N);
int vis[N];
int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (auto child : tree[cur_v])
        {
            if (vis[child])
                continue;

            q.push(child);
            vis[child] = 1;
            level[child] = level[cur_v] + 1;
        }
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
    bfs(1);

    return 0;
}