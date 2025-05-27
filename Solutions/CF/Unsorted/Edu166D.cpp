#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

// number of elements less than key in a
int orderOf(vector<int> &a, int key)
{
    if (key > a[a.size() - 1])
        return a.size();
    int lo = -1;
    int hi = a.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (a[mid] < key)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo + 1;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (s[i - 1] == '(')
            a[i]++;
        else
            a[i]--;
    }
    dbg(a);
    // find occurences of each value
    vector<vector<int>> freq(n);
    for (int i = 1; i <= n; i++)
    {
        freq[a[i]].push_back(i);
    }
    dbg(freq);
    // loop thru each prefix
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int prefix = a[i];
        int l = i + 1;
        // find r
        int r = n + 1;
        int x = 2 * prefix + 1;
        if (0 <= x && x <= n && freq[x].size() > 0 && freq[x].back() >= l)
        {
            r = freq[x][orderOf(freq[x], l)];
        }
        dbg(l, r, prefix);
        // find number of x's in [l ... r]
        int L = orderOf(freq[prefix], l);
        int R = orderOf(freq[prefix], r);
        dbg(L, R);
        ans += (R - L);
    }
    cout << ans << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}