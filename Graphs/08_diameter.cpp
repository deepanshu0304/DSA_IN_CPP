#include <bits/stdc++.h>
using namespace std;

/*
Diameter is the maximum possible distance between any two nodes...
How can it be calculated 
!Brute force-------
you will call dfs for each function and stores the max depth for that node 
and when all dfs are finished the max of stores value will be our ans
?Optimized way-----
we will call dfs from any vertex you want....so the node which will be at max vdepth from that vertex
will surely be one end of diameter...now treating this node as vertex we will call dfs and max depth will be our ans


*/



const int N = 1e3;
vector<vector<int>> tree(N);
int depth[N];

void dfs(int vertex, int parent= -1)
{

    
    for (auto child : tree[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        
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

    int m_depth_node;
    int max_depth = 0;
    for (int i = 1; i <= n;i++){
        if(depth[i]>max_depth){
            max_depth = depth[i];
            m_depth_node = i;

        }
        depth[i] = 0;
    }

    dfs(m_depth_node);

    for (int i = 0; i <= n;i++){
        if(depth[i]>max_depth){
            max_depth = depth[i];
        }
    }
    cout << max_depth;
    return 0;
}