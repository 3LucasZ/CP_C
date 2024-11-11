#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(3, -10*n));
    dp[0][0] = 0;
    for (int i=0;i<n;i++) {
        int tmp;
        // 0 -> 0
        tmp = (a[i+1]>dp[i][0]) - (a[i+1]<dp[i][0]);
        dp[i+1][0] = dp[i][0] + tmp;
        // 0 -> 1
        dp[i+1][1] = dp[i][0];

        // 1 -> 1
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
        // 1 -> 2
        tmp = (a[i+1]>dp[i][1]) - (a[i+1]<dp[i][1]);
        dp[i+1][2] = dp[i][1] + tmp;

        // 2 -> 2
        tmp = (a[i+1]>dp[i][2]) - (a[i+1]<dp[i][2]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][2] + tmp);
    }
    dbg(dp);
    int ans = max(dp[n][1], dp[n][2]);
    cout << ans << nl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}