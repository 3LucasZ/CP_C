#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 1e6;
unordered_map<ll, int> dp;

int solve(ll x){
    // cout << x << endl;
    if (!dp.count(x)) {
        if (x%2==0) dp[x]=solve(x/2)+1;
        else dp[x]=solve(3*x+1)+1;
    }
    return dp[x];
}

int main() {
    dp[1] = 1;
    for (int i=1;i<=n;i++){
        solve(i);
    }

    pair<ll, int> ans = {0,0};
    for (int i=1;i<=n;i++){
        ans = max(ans, {dp[i], i});
    }
    cout << ans.second << endl;

    
    // cout << solve(100) << endl;
    // for (auto p : dp){
    //     cout << "{" << p.first << ", " << p.second << "} ";
    // }
}