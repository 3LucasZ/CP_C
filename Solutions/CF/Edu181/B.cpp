#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void solve()
{
    ll A, B, K;
    cin >> A >> B >> K;
    if (A == 0 || B == 0)
    {
        cout << 1 << nl;
    }
    else
    {
        ll g = gcd(A, B);
        A /= g;
        B /= g;
        if (A <= K && B <= K)
        {
            cout << 1 << nl;
        }
        else
        {
            cout << 2 << nl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}