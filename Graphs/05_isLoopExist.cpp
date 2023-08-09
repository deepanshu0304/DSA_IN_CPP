#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];

bool vis[N];
bool dfs(int vertex,int par)
{
    auto isLoopExist = false;
    // cout << vertex << endl;
    vis[vertex] = true;
 
    for (int child : graph[vertex])
    {
        // cout << "par " << vertex << " child " << child << endl;
        if(vis[child] && child==par)
            continue;
        if (vis[child])
            return true;

        isLoopExist|= dfs(child,vertex);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bool ans = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;

        if(dfs(i,0)){
            bool ans = true;
            break;
        }

    }
    cout << ans;
    return 0;
}
