#include <bits/stdc++.h>
using namespace std;
/*
we generally run bfs starting from one source and assuming it's level to be zero
here we will run bfs from many source simultaneously assuming all are at zero level
we will understand it by question
*/

/*
given a grid of n *m having some value after each hour the value of a element changes and becomes the max of it's
neighbour this all happen simultaneously in whole grid you need to tell the max time so that all element become
equal
*/
const int N = 1e3 + 10;
const int INF = 1e9 + 7;
int value[N][N];
int level[N][N];
int vis[N][N];

int n, m;
bool isValid(int i, int j)
{
    return (
        i >= 0 && j >= 0 && i < n && i < m);
}

vector<pair<int, int>> movements = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, 1},
    {-1, 1},
    {1, -1},
    {-1, -1},
};

int bfs()
{ 
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, value[i][j]);
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (value[i][j] == mx)
                q.push({i, j});
            vis[i][j] = 1;
            level[i][j] = 0;
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        auto cur_v = q.front();
        int v_x = cur_v.first;
        int v_y = cur_v.second;
        q.pop();
        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second = v_y;
            if (!isValid(child_x, child_y))
                continue;
            if (vis[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            vis[child_x][child_y] = 1;
            level[child_x][child_y] = level[v_x][v_y] + 1;
            ans = max(ans, level[child_x][child_y]);
        }
    }

    return ans;
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                cin >> value[i][j];
            }
        }

        cout << bfs() << endl;
    }

    return 0;
}