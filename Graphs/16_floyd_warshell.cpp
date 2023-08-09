#include <bits/stdc++.h>
using namespace std;
/*
It is also known as all pair shortest parth algorithm
!Concept
Here one term isdefined as K it mean when we are finding shortest path betwee two nodes we can go only
through k nodes now we will tke diffrent values for k let's say 0
yhan the distance wiil be the edge connecting that pair
when we increase value of k there is two possibility
?first ---> shortedt distance remain same
?second --> shortest distance decrease
so the new shortest distance wiil come including k+1 vertex
suppose we are finding distance between i and j than
the distance i to j will be  equal to  sum of distance of i to k+1 and k+1 to j
*/
const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];
int main()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        dist[v1][v2] = wt;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //  if(dist[i][k]!=INF && dist[k][j]!=INF) // we need to use this in case of negative weights
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return 0;
}

/*
this algorithm can handle negative weights but can not handle negative weight cycle
*/