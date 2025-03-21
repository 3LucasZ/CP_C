// E. MEXimize the Score
// Used a hint unfortunately
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
    vector<int> f(n);
    for (int i=0;i<n;i++) f[a[i]]++;
    vector<ll> rhs(n);
    rhs[0] = n-f[0];
    for (int i=1;i<n;i++) rhs[i]=rhs[i-1]-f[i];
    for (int i=0;i<n;i++) rhs[i]=po(2,rhs[i]);
    dbg(n,a);
    dbg(f);
    dbg(rhs);

    ll ans = 0;
    vector<ll> dp(n+2);
    int maxk = n;
    for (int i=0;i<n;i++){
        int pmaxk = maxk;
        maxk = min(maxk, f[i]);
        dbg(i,maxk);

        ll col1 = 0;
        for (int k=maxk+1;k<=f[i];k++) col1+=chs(f[i],k);
        ll col2 = i==0?1:0;
        for (int k=maxk+1;k<=pmaxk;k++) {
            col2+=dp[k];
            dp[k]=0;
        }
        dbg(col1, col2);

        for (int k=maxk;k>0;k--){        
            ll tmp = chs(f[i], k);
            col1 = (col1+tmp)%MOD;
            ll newDp = (dp[k]*col1%MOD + col2*tmp%MOD)%MOD;
            col2 = (col2+dp[k])%MOD;
            dp[k]=newDp;
            ans = (ans + k*newDp%MOD*rhs[i]%MOD)%MOD;
        }
        dbg(dp);
    }
    cout << ans << nl;
}
int main() {
    setupChs();
    int t; cin >> t; while (t--) solve();
}