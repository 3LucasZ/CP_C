// E. MEXimize the Score
// Failed: didn't account for a crucial case
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll MOD = 998244353;
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}
const int MAXF = 2e5;
ll fact[MAXF+1];
ll invfact[MAXF+1];
void setupChs() {
    fact[0]=1; for (int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=po(fact[MAXF],MOD-2);
    for (int i=MAXF;i>=1;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll chs(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> cnt(n);
    for (int i=0;i<n;i++) cnt[a[i]]++;
    vector<ll> rhs(n);
    rhs[0] = n-cnt[0];
    for (int i=1;i<n;i++) rhs[i]=rhs[i-1]-cnt[i];
    for (int i=0;i<n;i++) rhs[i]=po(2,rhs[i]);
    dbg(n,a);
    dbg(cnt);
    dbg(rhs);

    ll ans = 0;
    vector<ll> m(n, 1);
    int maxk = n;
    for (int i=0;i<n;i++){
        maxk=min(maxk, cnt[i]);
        ll col = 0;
        for (int k=maxk;k>0;k--){
            ll cmp = chs(cnt[i], k);
            ans = (ans + k*cmp%MOD*m[k]%MOD*rhs[i]%MOD)%MOD;
            col = (col + cmp)%MOD;
            m[k] = (m[k] * col)%MOD;
        }
    }
    cout << ans << nl;
}
int main() {
    setupChs();
    int t; cin >> t; while (t--) solve();
}