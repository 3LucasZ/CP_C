#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

ll MOD = 123456789;

int main(){
    int L, S; cin >> L >> S;
    dbg(L,S);
    vector<ll> dp(L+1);
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=L;i++){
        dp[i] = (dp[i-1] - dp[max(i-S,1)-1] + MOD)%MOD;
        dp[i] = (dp[i] + dp[i-1])%MOD;
    }

    ll ans = 0;
    for (int i=0;i<S;i++){
        ans = (ans + (dp[L-i]-dp[L-i-1]+MOD)*(i+1))%MOD;
    }
    cout << ans << nl;
}