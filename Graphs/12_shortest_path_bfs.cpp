#include <bits/stdc++.h>
using namespace std;
/*
you are given with a chess boaard
now you need to tell the minimum no of move a knight should walk in order to reach its end point
*/
const int N = 1e5 + 10;
int getX(string s)
{

    return (s[0] - 'a');
}
int getY(string s)
{

    return (s[1] - '1');
}

int level[8][8];
int vis[8][8];
vector<pair<int, int>> movements{
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
};

bool isValid(int x, int y)
{

    if (x >= 0 && y >= 0 && x < 8 && y < 8)
    {
        return true;
    }
    else
        return false;
}

int bfs(string source, string dest)
{
    int sourcex = getX(source);
    int sourcey = getY(source);
    int destx = getX(dest);
    int desty = getY(dest);
    queue<pair<int, int>> q;
    q.push({sourcex, sourcey});
    vis[sourcex][sourcey] = 1; // becoz of optimization
    level[sourcex][sourcey] = 0;
    while (!q.empty())
    {
        pair<int, int> cur_pos = q.front();
        q.pop();
        int cur_x = cur_pos.first;
        int cur_y = cur_pos.second;
        for (auto movement : movements)
        {
            int x = cur_x + movement.first;
            int y = cur_y + movement.second;
            if (!isValid(x, y))
                continue;
            if (!vis[x][y])
            {
                q.push({x, y});
                vis[x][y] = 1;
                level[x][y] = level[cur_x][cur_y] + 1;
            }
        }
        // we can do one optimization here
        // our work is to get level of destx and desty when we get that we will break
        if (level[destx][desty] != -1)
        {
            break;
        }
    }

    return level[destx][desty];
}

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // level[i][j] = 0;
            level[i][j] = -1; // after optimization
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
        string start, end;
        cin >> start >> end;

        cout << bfs(start, end) << endl;
        ;
    }
    return 0;
}