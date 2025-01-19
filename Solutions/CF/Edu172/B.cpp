#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        a[x]++;
    }
    dbg(a);
    int cnt1 = 0;
    int diff = 0;
    for (int i=0;i<=n;i++) {
        if (a[i]==1) cnt1++;
        if (a[i]!=0) diff++;
    }
    cout << 2*((cnt1+1)/2) + (diff-cnt1) << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}