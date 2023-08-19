#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int par[N];
int siz[N];
/*
!Minimum spanning tree
given a grph we need to find a tree in that graoh such that
the sum of edges of that graph is minimum


Kruskal's Algorithm
we will treat each vertex as individual
and also store the edges in ascending order
now one by one we will take one edge and attach it to their respective node if after inseting that
edge there is no loop formation
we can do all the things but how we will fins that if after joinig edges loop id forming or not
we will find it using DSU
the loop possiblity will only be there if the two vertex of that edge is alrady in same connected component
*/

void make(int v)
{
    par[v] = v;
    siz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (siz[a] < siz[b]){
          par[a]=b;

}
else if{
par[b] = a;
}

        
        else{
par[a]=b;
siz[b]++;

}
    }
}
int main(){
    vector<pair<int, pair<int, int>>> edges;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        edges.push_back({wt, {v1, v2}});

    }
    sort(edges.begin(), edges.end());
    //Treating them as individual
    for (int i = 1; i <= n;i++){
        make(i);
    }
    int total_cost = 0;
    //Taking edges one by one
    for(auto edge:edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        // checking if we  are gonna insert that edge then there will be loop or not
        if(find(u)==find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        cout << u << " " << v << endl;
    }
    cout << total_cost << endl;
}