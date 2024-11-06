#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n, k; cin >> n >> k;
    if (n==1) {
        cout << 1 << nl;
        cout << 1 << nl;
        return;
    }
    if (k==1 || k==n) {
        cout << -1 << nl;
        return;
    }
    if (k%2==0) {
        cout << 3 << nl;
        cout << 1 << " " << k << " " << k+1 << nl;
    } else {
        cout << 5 << nl;
        cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << k+2 << nl;
    }
}
int main() {
    int T; cin >> T; while (T--) solve();
}