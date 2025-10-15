#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

struct edge
{
    int u, v, idx;
};
unordered_multiset<int> dfs(vector<vector<edge>> &tree, vector<int> &ans, edge e)
{
    unordered_multiset<int> ret;
    for (auto child_e : tree[e.u])
    {
        if (e.v == child_e.u)
            continue;
        auto ch = dfs(tree, ans, child_e);
        // Compute: ret = (ret + ch)
        if (ret.size() < ch.size())
        {
            for (auto x : ret)
                ch.insert(x);
            ret = ch;
        }
        else
        {
            for (auto x : ch)
                ret.insert(x);
        }
    }
    if (idx == -1)
        return;
    // now solve the edge: idx (par -> u)
    ans[idx] =
        return ret;
}
int main()
{
    int n;
    vector<vector<edge>> tree(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back({u, v, i});
        tree[v].push_back({v, u, i});
    }

    vector<int> ans(n);
    dfs(tree, ans, {0, 1, -1});
}