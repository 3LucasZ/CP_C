#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
void solve(vector<int> &a, vector<int> &pos, int n)
{
    int l, r, k;
    cin >> l >> r >> k;
    if (pos[k] < l || pos[k] > r)
    {
        cout << -1 << " ";
        return;
    }
    vector<int> L;
    vector<int> R;
    int Lcnt = 0;
    int Rcnt = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == k)
        {
            break;
        }
        else if (m < pos[k])
        {
            Lcnt++;
            if (a[m] > k)
                L.push_back(m);
            l = m + 1;
        }
        else
        {
            Rcnt++;
            if (a[m] < k)
                R.push_back(m);
            r = m - 1;
        }
    }
    if (Lcnt >= k || Rcnt >= n - k + 1)
    {
        cout << -1 << " ";
        return;
    }
    int x = min(L.size(), R.size());
    cout << 2 * x + 2 * (L.size() - x + R.size() - x) << " ";
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]] = i;
    }
    dbg(a);
    dbg(pos);
    for (int i = 0; i < q; i++)
        solve(a, pos, n);
    cout << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}