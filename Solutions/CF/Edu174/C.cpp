#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans = 0;
    ll pre = 0;
    ll cur = 0;
    ll ones = 0;
    for (int i=0;i<n;i++){
        if (a[i]==1) {
            pre = (pre*cur + cur)%MOD;
            cur = 1;
            ones ++;
        } else if (a[i]==2){
            cur = (cur*2)%MOD;
        } else {
            ans = (ans + pre*cur + cur)%MOD;
            ans = (ans - ones + MOD)%MOD;
        }
    }
    cout << ans << nl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}