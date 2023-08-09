#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e3 + 7;
const int INF = 1e9 + 7;
int par[N];
int siz[N];
/*
Given there are n cities numbered 1 to n
you can either build a power station in city or you can connect two citi to supply power
in them you need to tell the minimum cost to supply power to all cities
cost to build a connection between two cities is distance between them*(ki+kj)
distance can be find by |xi-xj| +|yi-yj|
!Input Format
First line ---> no of cities
next n lines ----> coordinate of city i.e x,y
given an array in which ith index tell the cost to build a power station in ith city
given an array in which ith index give the value of ki
!Output Format
first line ---> total cost
second line ---> NO. of power station
next line --> cities in which power station made by space seprated
next line ----> no of connection
next lines ---> cities in which connection are made
*/
/*
?Approach
we will connect each and every city by one another
and  now our work is that each city should have connection with minimum cost
so it's basicaly a minimum spanning tree
but we need to take power station in account
now we don't know for minimum connection how much power station we require
what we will do is we will let one extra node and connect that node to each city by a cost
equivalent to the instlation of power station...now we will apply minimum spannig tree in this graph
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
        if (siz[a] < siz[b])
            swap(a, b);
        par[b] = a;
        siz[a] += siz[b];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> coordinates(n + 1); // we want one based indexing
    for (int i = 1; i <= n; i++)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    vector<int> power_station_cost(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> power_station_cost[i];
    }

    vector<int> value_of_k(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> value_of_k[i];
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++)
    {
        edges.push_back({power_station_cost[i], {0, i}});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {

            int dist = abs(coordinates[i].first - coordinates[j].first) + abs(coordinates[i].second - coordinates[j].second);
            int wt = dist * (value_of_k[i] + value_of_k[j]);
            edges.push_back({wt, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int total_cost = 0;
    vector<int> power_station_cities;
    vector<pair<int, int>> connection;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find(u) == find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        if (u == 0 || v == 0)
        {
            power_station_cities.push_back(max(u, v));
        }
        else
        {
            connection.push_back({u, v});
        }
    }
    cout << total_cost << endl;
    cout << power_station_cities.size() << endl;
    for (auto i : power_station_cities)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << connection.size() << endl;
    for (auto i : connection)
    {
        cout << i.first << " " << i.second << endl;
    }
}