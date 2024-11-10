#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    int n, x; cin >> n >> x;
    ll sum = 0;
    ll mx = 0;
    for (int i=0;i<n;i++){
        ll a; cin >> a;
        sum += a;
        mx = max(mx,a);
    }
    cout << max((sum+x-1)/x, mx) << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}