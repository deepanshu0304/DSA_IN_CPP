#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
vector<vector<int>> cc;
vector<int> current_cc;  // we declared it globally so that we do not need to pass it to function
bool vis[N];
void dfs(int vertex)
{

    //cout << vertex << endl;
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for (int child : graph[vertex])
    {
        //cout << "par " << vertex << " child " << child << endl;
        if (vis[child])
            continue;

        dfs(child);
    }
}
/*
our motive is to count no of connected component in given forest 
what can we simply do is we will call dfs for any one   vertex
so now that will visit all the vertex that are in that componenet 
ony by one we will call dfs for each vertex that is not visited 
so no of connected component will be the no of types dfs called 
*/
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
    int count = 0;
    for (int i = 1; i <= n;i++){
        if(vis[i])
            continue;
        current_cc.clear();
        dfs(i);
        count++;
        cc.push_back(current_cc);
    }

    cout << count<<"\n";
    cout << cc.size()<<"\n";
    // for(auto i : cc){
    //     for(auto j:i){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}
/*
we can store connected component also
we will create a vector of vecore where we will store diffrent connected component
*/