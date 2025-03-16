#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve() {
    int n, x; ll k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int p;
    int a = 0;
    p = 0;
    for (int i=0;i<n;i++){
        if (s[i]=='L') p -= 1;
        else p += 1;
        a++;
        if (p==0) break;
        if (i==n-1) a = -1;
    }
    int b = 0;
    p = x;
    for (int i=0;i<n;i++){
        if (s[i]=='L') p -= 1;
        else p += 1;
        b++;
        if (p==0) break;
        if (i==n-1) b = -1;
    }
    // cout << a << " " << b << nl;

    ll ans = 0;
    if (k >= b && b != -1) {
        ans ++;
        k -= b;
        if (a != -1) ans += k / a;
    }
    cout << ans << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}   