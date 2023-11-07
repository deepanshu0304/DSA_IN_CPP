#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0, S}); //{dist,source}
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeWeight = it.second;
            int adjNode = it.first;
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode}); // in pq we store {dist,node} because the min dist remains on top of the pq
            }
        }
    }
    return dist;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V];
    // creating a weighted adj list
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // source/starting node
    int S;
    cin >> S;
    vector<int> dist;
    dist = dijkstra(V, adj, S);
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
