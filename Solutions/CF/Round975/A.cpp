#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    int n; cin >> n;
    int mx = 0;
    int mxi = 0;
    for (int i=1;i<=n;i++) {
        int x; cin >> x;
        if (x > mx || (x == mx && i%2==1)){
            mx = x;
            mxi = i;
        }
    }
    int ans = mx + (n+mxi%2)/2;
    cout << ans << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}