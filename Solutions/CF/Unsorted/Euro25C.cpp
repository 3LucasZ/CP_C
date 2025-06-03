#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(begin(a), end(a));
    dbg(a, k);
    int l = 0;
    int r = n - 1;
    deque<int> bigs;
    int ans = 0;
    while (true)
    {
        if (bigs.empty())
        {
            bigs.push_back(a[r]);
            r--;
        }
        if (l == r)
        {
            bigs.push_back(a[l]);
            break;
        }

        while (a[l] + a[r] >= k && l < r)
        {
            bigs.push_back(a[r]);
            r--;
        }
        if (l == r)
        {
            bigs.push_back(a[l]);
            break;
        }

        ans++;
        bigs.pop_front();
        dbg(l, r);
        dbg(bigs);
        l++;
        r--;
        if (l > r)
            break;
        if (l == r)
        {
            bigs.push_back(a[l]);
            break;
        }
    }
    dbg(bigs);

    // part 2
    while (bigs.back() < k && bigs.size() >= 2)
    {
        bigs.pop_back();
        bigs.pop_front();
        ans++;
    }
    ans += bigs.size();
    cout << ans - 1 << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}