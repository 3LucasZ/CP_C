#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    // iterate over levels
    ll ans = 0;
    int r = n;
    ll mult = 1;
    ll cons = n+1;
    for (int i=0;i<n;i++){
        // size too small, stop
        if (r < k) break;
        //calculate the level
        if (r%2==1) ans += mult * cons;
        //propagate
        mult*=2;
        r/=2;
    }
    cout << ans/2 << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}