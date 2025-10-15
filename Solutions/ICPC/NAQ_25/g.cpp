#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll MOD = 998244353;
ll po(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return po(a * a % MOD, b / 2);
    else
        return a * po(a, b - 1) % MOD;
}
ll inv(ll a)
{
    return po(a, MOD - 2);
}
int main()
{
    ll n, k;
    cin >> n >> k;
    cout << n * po((2 * k * inv(2 * k + 1)) % MOD, 2 * k) % MOD << nl;
}