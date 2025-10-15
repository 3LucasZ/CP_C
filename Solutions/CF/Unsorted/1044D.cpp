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
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dbg(n, a);

    // 0 => black, 1 => red (chopped)
    vector<vector<ll>> dp(n + 2, vector<ll>(2, -1e12));
    dp[0][0] = 0;
    for (ll i = 0; i <= n; i++)
    {
        dp[i + 1][0] = max({dp[i + 1][0], dp[i][0], dp[i][1]});
        dp[i + 1][1] = max({dp[i + 1][1], dp[i][0] + min(i + 1, a[i + 2]), dp[i][1] + 1});
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans - dp[n][0] << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}