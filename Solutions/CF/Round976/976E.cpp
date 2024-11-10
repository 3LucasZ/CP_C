#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();
ll MOD = 1e9+7;

ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

int n;
vector<int> a;
vector<int> p;

void solve() {
    cin >> n;
    a.resize(n+1); p.resize(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> p[i];
    }
    dbg(n);dbg(a);dbg(p);
    // ll div = 285700002; //10000^-1 under MOD calculated online!
    ll div = po(10000, MOD-2);
    dbg(div);

    vector<vector<ll>> dp(n+1, vector<ll>(1024)); dp[0][0] = 1;
    for (int i=0;i<=n-1;i++){
        for (int xr=0;xr<=1023;xr++){
            dp[i][xr]%=MOD;
            dp[i+1][xr^a[i+1]] += (dp[i][xr]*p[i+1]%MOD)*div%MOD;
            dp[i+1][xr] += (dp[i][xr]*(10000-p[i+1])%MOD)*div%MOD;
        }
    }

    ll ans = 0;
    for (int xr=0;xr<=1023;xr++){
        ans%=MOD;
        ans += (dp[n][xr]*xr%MOD)*xr%MOD;
    }
    cout << ans << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}