#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void dfs(int node, int par, vector<vector<int>> &graph, vector<int> &p, vector<int> &color, vector<int> &bc, int &bc2, int &bc3, int &cc, int &xor_rt, int &b)
{
    for (int child : graph[node])
    {
        if (child != par)
        {
            dfs(child, node, graph, p, color, bc, bc2, bc3, cc, xor_rt, b);
            p[child] = node;
        }
    }
    if (color[node] == 1)
        b++;
    if (color[node] == 1)
        bc[par]++;
    if (bc[node] == 2)
    {
        bc2++;
        xor_rt ^= node;
    }
    else if (bc[node] > 2)
    {
        bc3++;
    }
    if (bc[node] == 1 && bc[par] == 0)
    {
        cc++;
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    dbg(color);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dbg(graph);
    vector<int> p(n + 1);
    vector<int> bc(n + 1);
    int bc2 = 0, bc3 = 0, cc = 0, xor_rt = 0, b = 0;
    if (color[1] == 1)
        cc++;
    dfs(1, 0, graph, p, color, bc, bc2, bc3, cc, xor_rt, b);
    dbg(p);
    dbg(bc);
    dbg(bc2, bc3, cc, xor_rt, b);
    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        // part 1: update bc
        int v = p[u];
        int oldBc = bc[v];
        int newBc = bc[v];
        if (color[u] == 0)
        {
            color[u] = 1;
            newBc++;
            b++;
        }
        else
        {
            color[u] = 0;
            newBc--;
            b--;
        }
        bc[v] = newBc;
        if (oldBc == 2)
        {
            bc2--;
            xor_rt ^= v;
        }
        else if (oldBc > 2)
            bc3--;
        if (newBc == 2)
        {
            bc2++;
            xor_rt ^= v;
        }
        else if (newBc > 2)
            bc3++;
        // part 2: update cc
        if (color[v] == 0 && color[u] == 1)
            cc++;
        else if (color[v] == 0 && color[u] == 0)
            cc--;
        if (color[u] == 0)
        {
            cc += bc[u];
        }
        else
        {
            cc -= bc[u];
        }
        // part 3: query
        dbg(color);
        dbg(bc);
        dbg(bc2, bc3, cc, xor_rt, b);
        bool ok = false;
        if (bc2 <= 1 && bc3 == 0 && cc <= 1 && b > 0)
        {
            if (xor_rt == 0 || (xor_rt <= n && bc[xor_rt] == 2 && color[p[xor_rt]] == 0))
            {
                ok = true;
            }
        }
        if (ok)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}