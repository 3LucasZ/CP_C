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
ll inv(ll a){
    return po(a,MOD-2);
}
ll denom = inv(10000);


int n;
vector<int> a;
vector<int> p;
vector<vector<ll>> dp;

void prob(int i, int j){
    dp.clear(); dp.resize(2,vector<ll>(2));
    dp[0][0] = 1;
    for (int x=0;x<n;x++){
        vector<vector<ll>> tmp(2,vector<ll>(2));
        ll pp = p[x+1]*denom%MOD;
        ll np = (10000-p[x+1])*denom%MOD;
        for (int bi=0;bi<2;bi++){
            for (int bj=0;bj<2;bj++){
                int bii = bi^!!(a[x+1]&(1<<i));
                int bjj = bj^!!(a[x+1]&(1<<j));
                tmp[bi][bj] = (tmp[bi][bj] + dp[bi][bj]*np)%MOD;
                tmp[bii][bjj] = (tmp[bii][bjj] + dp[bi][bj]*pp)%MOD;
            }
        }
        dp=tmp;
    }
}

void solve() {
    cin >> n;
    a.resize(n+1); p.resize(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        cin >> p[i];
    }

    ll ans = 0;
    for (int i=0;i<=10;i++){
        prob(i,i);
        ans += dp[1][1]*(1<<(i+i))%MOD;
        for (int j=i+1;j<=10;j++){
            prob(i,j);
            ans += 2*dp[1][1]*(1<<(i+j))%MOD;
        }
    }
    cout << ans%MOD << nl;
}

int main() {
    dbg(denom);
    dbg(5*inv(2)%MOD);
    int t; cin >> t; while (t--) solve();
}