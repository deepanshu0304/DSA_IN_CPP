#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 7;
vector<vector<pair<int, int>>> graph(N);
vector<int> dist(N, INF);
vector<int> visited(N, 0);

void dijkstra_algo(int source)
{
    set<pair<int, int>> s; // you can use priority queue here and also multiset but set will also work so we will use set
    s.insert({0, source});
    dist[source] = 0;
    while (s.size() > 0)
    {
        auto node = *s.begin();
        int v = node.second;
        int wt = node.first;
        s.erase(s.begin());
        if (visited[v])
            continue;
        visited[v] = 1;
        for (auto child : graph[v])
        {
            int child_v = child.first;
            int child_wt = child.second;
            if (dist[v] + child_wt < dist[child_v])
            {
                dist[child_v] = dist[v] + child_wt;
                s.insert({dist[child_v], child_v});
            }
        }
    }
}
// time complexity is 0(V+E*log(V))....log(v) is becox of insertion operation in set
int main()
{
    int n, m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2, wt});
    }
    dijkstra_algo(1);
    return 0;
}
