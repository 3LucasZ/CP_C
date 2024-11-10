#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()





int main() {
    int n; int k; cin >> n >> k;
    vector<int> mvs(k);
    for (int i=0;i<k;i++){
        cin >> mvs[i];
    }

    vector<bool> dp(n+1);
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++){
            if (i-mvs[j]>=0) dp[i] = dp[i] || !dp[i-mvs[j]];
        }
    }

    for (int i=1;i<=n;i++) {
        if (dp[i]){
            cout << "W";
        } else {
            cout << "L";
        }
    }
    cout << nl;
}