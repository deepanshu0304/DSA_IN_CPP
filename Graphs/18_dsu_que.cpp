#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
/*
there are n people you are given with q query 
in each query you are given with two input which two are emerging
in each query after emerging you need to print the diffrence between the maximum size group
and minimum size group....

?Conept....
we need to store the size in multiset 
and we will create one function where wenwill increase and decrease the size....
you would have said we have one size array  already why don't we use that ..it is adviseable 
to not disturb previous funct just make another and play with them
*/
int par[N];
int siz[N];
multiset<int> sizes;
void make(int v)
{
    par[v] = v;
    siz[v] = 1;
    sizes.insert(1);
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}
void merge(int a,int b){
    // sizes.erase(siz[a]);  as it will erase all the present value 
    sizes.erase(sizes.find(siz[a]));
    // sizes.erase(siz[b]);
    sizes.erase(sizes.find(siz[b]));
    sizes.insert(siz[a] + siz[b]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        par[b] = a;
        merge(a, b);
        siz[a] += siz[b];
    }
}

int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {

        int v1, v2;
        cin >> v1 >> v2;
        Union(v1, v2);
        if(sizes.size()==1)
            cout << 0 << endl;
            else
            {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx - mn << "\n";
            }
    }

    return 0;
}
