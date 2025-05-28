// Problem: https://codeforces.com/problemset/problem/1553/E
// Rating: 2100
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int numSwaps(const vector<int> &q)
{
    int n = q.size() - 1;
    vector<bool> vis(n + 1);
    int cycles = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        cycles++;
        int u = i;
        while (!vis[u])
        {
            vis[u] = true;
            u = q[u];
        }
    }
    return n - cycles;
}
vector<int> vlshift(vector<int> &p, int x)
{
    int n = p.size() - 1;
    vector<int> ret(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int j = i + x;
        if (j > n)
            j -= n;
        ret[i] = p[j];
    }
    return ret;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    // shifts[i] contains the elements of p that align with p' shifted right cyclically by i
    vector<vector<int>> shifts(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int shift = p[i] - i;
        if (shift > 0)
            shift -= n;
        shift *= -1;
        shifts[shift].push_back(i);
    }
    dbg(shifts);
    // find which shifts are possible (max = 3)
    vector<int> poss;
    for (int i = 0; i < n; i++)
    {
        if (shifts[i].size() >= 1 * n / 3)
        {
            poss.push_back(i);
        }
    }
    dbg(poss);
    // actually check the poss
    vector<int> ans;
    for (int shift : poss)
    {
        if (numSwaps(vlshift(p, shift)) <= m)
            ans.push_back(shift);
    }
    // ret
    cout << ans.size() << " ";
    for (int x : ans)
        cout << x << " ";
    cout << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}