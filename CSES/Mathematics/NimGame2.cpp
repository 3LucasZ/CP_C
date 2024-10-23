#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()



void solve() {
    int n; cin >> n;
    int xorsum = 0;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        xorsum ^= (x%4);
    }
    if (xorsum==0) cout << "second" << nl;
    else cout << "first" << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}