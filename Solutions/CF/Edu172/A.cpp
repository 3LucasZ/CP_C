#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(all(a), greater<int>());
    dbg(a);
    int sum = 0;
    for (int i=0;i<n;i++){
        if (sum + a[i] > k) break;
        sum += a[i];
    }
    cout << k - sum << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}