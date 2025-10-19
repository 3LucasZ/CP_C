#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

vector<vector<int>> g;
vector<bool> vis;
vector<int> topsort;
void dfs(int u)
{
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
            dfs(v);
    topsort.push_back(u);
}
int main()
{
    int n = 5;
    g.resize(n + 1);
    g[1].push_back(2);
    g[1].push_back(3);
    g[1].push_back(4);
    g[1].push_back(5);
    g[2].push_back(3);
    g[2].push_back(5);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    reverse(begin(topsort), end(topsort));
    dbg(topsort);
}