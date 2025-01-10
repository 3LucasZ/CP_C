#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int l, r; cin >> l >> r;
    dbg(l,r);
    int prefix = 0;
    for (int i=30;i>=0;i--){
        //find first different bit
        if (((1<<i)&l) != ((1<<i)&r)) {
            int a = prefix + (1<<i);
            int b = prefix + (1<<i) - 1;
            int c;
            if (b!=l) c = l;
            else c = r;
            cout << a << " " << b << " " << c << nl;
            return;
        }
        prefix += ((1<<i)&l);
    }
}
int main() {
    int t; cin >> t; while (t--) {
        solve();
    }
}