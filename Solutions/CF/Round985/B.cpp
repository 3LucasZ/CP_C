#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    dbg(n, s, t);
    int zero = 0;
    int one = 0;
    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            zero++;
        } else {
            one++;
        }
    }
    for (int i=0;i<n-2;i++){
        if (t[i]=='0') {
            one--;
        } else {
            zero--;
        }
    }
    if (zero <= 0 || one <= 0) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}