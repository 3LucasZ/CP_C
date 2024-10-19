#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    ll n; cin >> n;
    ll k; cin >> k;
    ll sum = 0; ll mx = 0;
    for (int i=0;i<n;i++){
        ll x; cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    int x = min((sum+k)/mx,n);
    for (;x>=1;x--){
        if ((sum+x-1)/x <= (sum+k)/x) {
            cout << x << nl;
            return;
        }
    }
}

int main() {
    int t; cin >> t; while (t--) solve();
}