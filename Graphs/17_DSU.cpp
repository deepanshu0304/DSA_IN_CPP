#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
/*
!Concept---
DSU is basically a data strucure
it have three function make, find , union
?Make --  it will make a seprate node
?Find --  it will return the parent or root node
?Union --- it will join the sets containig them (it joins set through their root node)

*/

int par[N];
int siz[N];

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
/*
one more optimization is known as path compression
when we know par of a is b par of b is c and par of c is d then we will directly connect a and b to d
this we will do during the process of finding parent
*/
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        par[b] = a;
        siz[a] += siz[b];
    }
}

/*
Now these have problems as we are blindly combining two diffrent trees there will be problem when
a very long tree will be connected with small tree then the depth of tree will be very long
so to optimize this wen use a technique that we always connect a small tree in big tree
*/
int main()
{
    // we will write code for finding connected components
    // two input n no of vertex and k query 
    // in each query given with two value which are connected
    // you need to find the no of connected components

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n;i++){
        make(i);
    }
        while (k--)
        {

        int v1, v2;
        cin >> v1 >> v2;
        Union(v1, v2);
        }
   
   // ?concept
   // no of connectd comp will be equal to count of value which are thier own parents
        int connected_comp = 0;
        for (int i = 1; i <= n;i++){
            if (par[i]==i)
            connected_comp++;
        }
        cout << connected_comp << endl;
        return 0;
}

/*
let's talk about time complexity
it has amotorized time complexity what it mean you can simply understand that the time complecity of this function
is
?almost constant
 over a numer of operation
*/