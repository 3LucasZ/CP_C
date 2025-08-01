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
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> l(N);
    vector<int> r(N);
    vector<ll> p(N);
    vector<ll> q(N);
    vector<ll> pq(N);
    vector<vector<int>> ri(M + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
        ri[r[i]].push_back(i);
        pq[i] = p[i] * po(q[i], MOD - 2) % MOD;
    }
    dbg(ri);
    vector<ll> rneg(M + 1, 1);
    for (int i = 1; i <= M; i++)
    {
        for (int j : ri[i])
        {
            rneg[i] = rneg[i] * (1 - pq[j] + MOD) % MOD;
        }
        rneg[i] = rneg[i] * rneg[i - 1] % MOD;
    }
    dbg(rneg);
    vector<ll> dp(M + 1);
    dp[0] = 1;
    for (int i = 1; i <= M; i++)
    {
        for (int j : ri[i])
        {
            ll other = rneg[i] * po(rneg[l[j] - 1], MOD - 2) % MOD;
            ll change = dp[l[j] - 1] * pq[j] % MOD * po(1 - pq[j] + MOD, MOD - 2) % MOD * other % MOD;
            dp[i] = (dp[i] + change) % MOD;
        }
    }
    dbg(dp);
    cout << dp[M] << nl;
}