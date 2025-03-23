#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
const int bits = 63;
const ll INF =  1e18;
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a,b/2);
    else return a*po(a,b-1);
}

int main() {
    // dp precomp
    vector<vector<ll>> dp(bits, vector<ll>(bits, INF));
    dp[0][0] = 0;
    for (int k=1;k<bits;k++){
        vector<vector<ll>> new_dp(bits, vector<ll>(bits, INF));
        for (int i=0;i<bits;i++){
            for (int j=0;j<bits;j++){
                if (i+k<bits) new_dp[i+k][j] = min(new_dp[i+k][j], dp[i][j] + po(2, k));
                if (j+k<bits) new_dp[i][j+k] = min(new_dp[i][j+k], dp[i][j] + po(2, k));
                new_dp[i][j] = min(new_dp[i][j], dp[i][j]);
            }
        }
        dp = new_dp;
    }
    int t; cin >> t; while (t--) {
        ll x, y;
        cin >> x >> y;
        // ans = min cost over all working shifts
        ll ans = INF;
        for (int i=0;i<bits;i++){
            for (int j=0;j<bits;j++){
                if ((x>>i)==(y>>j)) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        cout << ans << nl;
    }
}