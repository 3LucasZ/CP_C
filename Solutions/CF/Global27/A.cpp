#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    ll r, c, r0, c0; 
    cin >> r >> c >> r0 >> c0;
    cout << (c)*(r-r0)+(c-c0)+(c-1)*(r-r0) << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}