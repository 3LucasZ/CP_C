#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << "YES" << nl;
        cout << 1 << nl;
        cout << 1 << nl;
        return;
    }
    else if (2 * k <= n + 1)
    {
        cout << "YES" << nl;
        cout << 2 << nl;
        // n = pq + r
        ll r = k - 1;
        ll p = n - r;
        ll q = 1;
        cout << p << " " << 1 << nl;
    }
    else
    {
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