#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> group_ids;
    map<int, vector<int>> group_vals;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        group_ids[x / 4].push_back(i);
        group_vals[x / 4].push_back(x);
    }

    for (auto &group : group_vals)
    {
        sort(begin(group.second), end(group.second));
    }
    dbg(group_ids);
    dbg(group_vals);
    vector<int> res(n);
    for (auto &group : group_ids)
    {
        for (int i = 0; i < group.second.size(); i++)
        {
            int val = group_vals[group.first][i];
            int id = group.second[i];
            res[id] = val;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}