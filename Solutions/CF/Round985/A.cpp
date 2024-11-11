#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    ll l, r, k; 
    cin >> l >> r >> k;
    dbg(l, r, k);
    ll lo = l-1; ll hi = r;
    while (lo < hi) {
        ll x = (lo+hi+1)/2;
        if (k*x<=r) { //good
            lo = x;
        } else { //bad
            hi = x-1;
        }
    }
    cout << lo-l+1 << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}