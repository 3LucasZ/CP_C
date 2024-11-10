#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

ll MOD = 998244353;

//a ^ b
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

//a choose b
//M1: chs(N,K) = n!/[k!(n-k)!]
//M2: chs(N,K) = chs(N,K-1)*(N-K+1)/K
const int MAXF = 200000;
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

int n;
vector<int> freq;

void solve() {
    cin >> n;
    freq.clear(); freq.resize(n+1);
    for (int i=0;i<n;i++){
        int x; cin >> x;
        freq[x]++;
    }
    dbg(n,freq);

    //fi...fn sum
    vector<ll> freqgeq(n+1);
    for (int i=n-1;i>=0;i--){
        freqgeq[i]=freqgeq[i+1]+freq[i];
    }
    dbg(freqgeq);

    //dp
    ll ans = 0;
    vector<ll> dp(freq[0]+1);
    //base
    for (int mn=0;mn<=freq[0];mn++){
        dp[mn]=chs(freq[0],mn);
        ans = (ans + dp[mn]*mn%MOD*po(2,freqgeq[1]))%MOD;
    }
    //transitions
    for (int i=1;i<=n;i++){
        dbg(i-1, dp);
        vector<ll> tmp(freq[i]+1);
        //track chsum
        ll chsum = 0;
        //Case 2: mn is equal to last min
        for (int mn=freq[i];mn>=0;mn--){
            chsum += chs(freq[i], mn);
            if (mn<=freq[i-1]){
                tmp[mn] += dp[mn]*chsum;
            }
        }
        //create dpsum
        for (int mn=freq[i-1]-1;mn>=0;mn--){
            dp[mn]=(dp[mn]+dp[mn+1])%MOD;
        }
        //Case 1: mn is the new min
        for (int mn=0;mn<=freq[i];mn++){
            if (mn+1<=freq[i-1]) {
                tmp[mn] += dp[mn+1]*chs(freq[i], mn);
            }
            //upd ans
            tmp[mn]%=MOD;
            ans = (ans + tmp[mn]*mn%MOD*po(2,freqgeq[i+1]))%MOD;
        }
        //swap
        dp.clear();
        dp = tmp;
    }
    cout << ans << nl;
}
int main() {
    setupChs();
    int t; cin >> t; while (t--) solve();
}