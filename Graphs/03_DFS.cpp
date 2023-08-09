#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
bool vis[N];
void dfs(int vertex)
{
    /*
    Take action on vertex after entring vertex
    */
    // if(vis[vertex])
    //     return;    .... this code will also work in place  if (vis[child]) continue;chr
    cout << vertex << endl;
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        cout << "par " << vertex << " child " << child << endl;
        if (vis[child])
            continue;
        /*
        Take Action on child before entring child node
        */
        dfs(child);
        /*
        Take action on child after exiting child node
        */
    }
    /*
    Take action on vertex before exiting the vertex
    */
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
    dfs(1);
    return 0;
}

/*
Time complexity
our function will be called v times as there are v vertex
and internal for loop if we add for all vertex then internal for loops 2*E time chlaa hoga
so overall complexity
0(V+2E) which is equal 0(V+E)
*/