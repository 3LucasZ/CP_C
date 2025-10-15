#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int solve()
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<ll> q(n + 1);
    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++)
    {
        q[i + 1] = q[i] + -1 + 2 * (a[i] - '0');
        p[i + 1] = p[i] + -1 + 2 * (b[i] - '0');
    }
    dbg(q, p);

    sort(begin(p) + 1, end(p));
    vector<ll> psum(n + 2);
    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + p[i];
    }
    psum[n + 1] = psum[n];
    dbg(psum);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(begin(p) + 1, end(p), -q[i]);
        ll k = it - begin(p) - 1;
        ll lsum = psum[k] + k * q[i];
        ll rsum = psum[n] - psum[k] + (n - k) * q[i];
        dbg(k, lsum, rsum);
        ans += -1 * lsum + 1 * rsum;
    };
    cout << (n * n * (n + 1) - ans) / 2 << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}