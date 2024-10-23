#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int l1, r1;
    int l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int ans = 0;
    if (l1==l2) ans--;
    if (r1==r2) ans--;

    int L = max(l1,l2);
    int R = min(r1,r2);
    dbg(L,R,ans);

    cout << max(1, R-L+2+ans) << nl;
}

int main() {
    int T; cin >> T; while (T--) solve();
}