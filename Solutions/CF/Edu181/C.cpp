#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll ans(ll X)
{
    vector<int> in = {2, 3, 5, 7, 30, 42, 70, 105};
    vector<int> out = {6, 10, 14, 15, 21, 35, 210};
    ll ans = 0;
    for (int d : in)
    {
        ans += X / d;
    }
    for (int d : out)
    {
        ans -= X / d;
    }
    return X - ans;
}
void solve()
{
    ll L, R;
    cin >> L >> R;
    cout << ans(R) - ans(L - 1) << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}