#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

ll solve() {
    ll n, b, c;
    cin >> n >> b >> c;

    if (b==0) {
        if (n <= c) return n;
        else if (n <= c+2) return n-1;
        else return -1;
    } else {
        if (c > n-1) {
            return n;
        }
        ll k = (n-1-c)/b;
        dbg(k);
        //k+1 terms are good.
        return n-(k+1);
    }
}
int main() {
    int t; cin >> t;
    while (t--) cout << solve() << nl;
}