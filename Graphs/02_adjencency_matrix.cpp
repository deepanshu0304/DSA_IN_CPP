#include <bits/stdc++.h>
using namespace std;
/*
Adjencency matrix is one method to store tthe grpah....suppose ou are given that there are n vertex and m edges
so you will create a matrix of n*n and you will store 1 corrosponding to the location which vertex are connected
*/
/*
Here is how you will be given the input for graphss
N,M  where N is veertex and M are edges
for next M line you will be given two integer which will show whch two vertex are connected
for eg
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
const int N = 1e3;
int graph1[N][N];
vector<int> graph2[N];
//vector<pair<int,int>> graph2[N];
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        // Matrix
        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt; // beacuse we are dealing with undidrected graphs
        // now if weight is not given you can insert 1 in place of weight

        //List
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
        // now what if we have to insert weight..then insted of vector<int> we need to declare vector<pair>
        // graph2[v1].push_back({v2, wt});
        // graph2[v2].push_back({v1, wt});
    }
    /*
    Now there is problem with matrix method....
    space complexity ---> 0(n^2)...
    now suppose you are given with n=1e5...we know max continous memory allocation is 1e7 or 1e8
    so here this method fail......
    */

    // Here comes the adjencency list
    // we will discuss it in same file itself..
    // here space complexity is 0(V+E) where V is vertex and E is edge

    // now suppose sometime you have to find whether this and this vertex is connected or not
    // if connected then what is the weight 
    // now it will be easy in matrix form    as we can fnd it in 0(1) complexity
    // but in list form it will take more complexity so acc to que we have to select our method
    return 0;
}