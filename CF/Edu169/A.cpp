#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    int a; int b; cin >> a >> b;
    int tmp;
    for (int i=0;i<n-2;i++){
        cin >> tmp;
    }
    if (n==2 && b-a>1) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
    int T; cin >> T; while (T--) solve();
}