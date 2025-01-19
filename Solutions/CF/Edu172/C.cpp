#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    ll k;
    string s;
    cin >> n >> k >> s;
    dbg(n,k,s);
    vector<int> a(n);
    for (int i=0;i<n;i++){
        if (s[i] == '1') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }
    for (int i=n-2;i>=0;i--){
        a[i]+=a[i+1];
    }
    // not allowed to use this dude.
    a[0] = -1e9; 
    dbg(a);
    sort(all(a), greater<int>());
    dbg(a);
    ll sum = 0;
    for (int i=0;i<n;i++){
        sum += a[i];
        if (sum >= k) {
            cout << i+2 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}