#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int par, int col , vector<vector<int>>& adj, vector<int>& vis){

    vis[src] = col;
    for(auto a: adj[src]){
        if(vis[a]==-1){
            dfs(a, src, col, adj, vis);
        }
    }
}

int main()
{
    int n,  p;
    cin >> n >> p;
    vector<pair<int, int>> v(p);
    for (int i = 0; i < p;i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < p;i++){
        int u = v[i].first;
        int w = v[i].second;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int no_of_cc = 0;
    vector<int> vis(n, -1);
    for (int i = 0; i < n;i++){
        if(vis[i]==-1){
            dfs(i, -1, no_of_cc, adj, vis);
            no_of_cc++;
            
        }
    }

    vector<int> diff_color(no_of_cc,0);
    for (int i = 0; i < n;i++){
        diff_color[vis[i]]++;
    }
    long long ans = 0;
    int till_now = 0;
    for (int i = 0; i < no_of_cc;i++){
        ans = ans + 1ll*diff_color[i] * (n - till_now - diff_color[i]);
        till_now += diff_color[i];
    }

    cout << ans << endl;

    return 0;
}