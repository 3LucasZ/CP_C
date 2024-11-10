#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int X,Y,K; cin >> X >> Y >> K;
    cout << 0 << " " << 0 << " "  << min(X,Y) << " " << min(X,Y) << nl;
    cout << 0 << " " << min(X,Y) << " " << min(X,Y) << " " << 0 << nl;
    dbg(min(X,Y)*min(X,Y), K);
}
int main() {
    int T; cin >> T; while (T--) solve();
}