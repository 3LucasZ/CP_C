#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int n;
vector<vector<int>> a;

void solve() { 
    cin >> n;
    a.clear(); a.resize(2, vector<int>(n+3));
    for (int r=0;r<2;r++){
        for (int c=1;c<=n;c++){
            char x; cin >> x;
            if (x=='A') a[r][c] = 1;
        }
    }
    dbg(n); dbg(a[0]); dbg(a[1]);

    vector<vector<int>> dp(n+3, vector<int>(3, -1e6)); dp[0][0] = 0;
    for (int i=0;i<n;i++){
        // CASE 0
        dp[i+2][1] = max(dp[i+2][1], dp[i][0] 
        + (a[0][i+1] + a[1][i+1] + a[0][i+2])/2);
        dp[i+2][2] = max(dp[i+2][2], dp[i][0]
        + (a[0][i+1] + a[1][i+1] + a[1][i+2])/2);
        dp[i+3][0] = max(dp[i+3][0], dp[i][0]  
        + (a[0][i+1] + a[0][i+2] + a[0][i+3])/2 
        + (a[1][i+1] + a[1][i+2] + a[1][i+3])/2);
        // CASE 1
        dp[i+1][0] = max(dp[i+1][0], dp[i][1] 
        + (a[1][i] + a[1][i+1] + a[0][i+1])/2);
        dp[i+3][1] = max(dp[i+3][1], dp[i][1] 
        + (a[1][i] + a[1][i+1] + a[1][i+2])/2 
        + (a[0][i+1] + a[0][i+2] + a[0][i+3])/2);
        // CASE 2
        dp[i+1][0] = max(dp[i+1][0], dp[i][2] 
        + (a[0][i] + a[1][i+1] + a[0][i+1])/2);
        dp[i+3][2] = max(dp[i+3][2], dp[i][2] 
        + (a[0][i] + a[0][i+1] + a[0][i+2])/2 
        + (a[1][i+1] + a[1][i+2] + a[1][i+3])/2);
    }

    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << ans << nl;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}