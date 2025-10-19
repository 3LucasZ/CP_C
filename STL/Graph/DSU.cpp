#include <bits/stdc++.h>
#include "debug.cpp"
typedef long long ll;
using namespace std;

/*
Disjoint Set Union
0 indexed
O(1) time per operation
csz[x] = component size = size of the component with head x
p[x] = parent of x (if p[x] is -1, then x is a head)
Tested: NO
*/
class DSU
{
public:
    int sz;
    vector<int> p;
    vector<int> csz;
    DSU(int sz)
    {
        this->sz = sz;
        p = vector<int>(sz, -1);
        csz = vector<int>(sz, 1);
    }
    int par(int v)
    {
        if (p[v] == -1)
            return v;
        p[v] = par(p[v]);
        return p[v];
    }
    void join(int u, int v)
    {
        int U = par(u);
        int V = par(v);
        // same component, do nothing
        if (U == V)
            return;
        // force csz[V] < csz[U]
        if (csz[U] < csz[V])
            swap(U, V);
        // union
        p[V] = U;
        csz[U] += csz[V];
    }
    bool connected(int u, int v)
    {
        return par(u) == par(v);
    }
};

int main()
{
    DSU dsu = DSU(10);
    dbg(dsu.connected(1, 3));
    dsu.join(1, 2);
    dsu.join(1, 6);
    dsu.join(2, 4);
    dsu.join(6, 4);
    dsu.join(3, 4);
    dbg(dsu.connected(1, 3));
}