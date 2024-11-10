#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

//TODO: switch off when not testing!
bool multi = false; 

int m, n;


void solve() {
    cin >> m >> n;
    vector<int> a;
    for (int i=0;i<m;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    dbg(m,n,a);

    vector<int> dp(n+1);
    vector<int> presum(n+2);
    int points = 0;
    for (int i=0;i<m;i++){
        if (a[i]==0){
            for (int I=0;I<=n;I++){
                if (I!=0) presum[I] += presum[I-1];
                dp[I] = dp[I] + presum[I];
            }
            for (int I=n;I>=1;I--){
                dp[I] = max(dp[I], dp[I-1]);
            }
            fill(presum.begin(), presum.end(), 0);
            points++;
        }
        else if (a[i] > 0){
            if (a[i]<=points){
                presum[a[i]]++;
                presum[points+1]--;
            }
        } else {
            if (points+a[i]>=0){
                presum[0]++;
                presum[points+a[i]+1]--;
            }
        }
        dbg(i,a[i]);
        dbg(presum);
        dbg(dp);
    }
    for (int I=0;I<=n;I++){
        if (I!=0) presum[I] += presum[I-1];
        if (dp[I] > -1) dp[I] = dp[I] + presum[I];
    }

    int ans = 0;
    for (int i=0;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << nl;
}

int main() {
    int q; 
    if (multi) cin >> q;
    else q = 1;
    for (int i=0;i<q;i++) solve();
}