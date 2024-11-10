#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    unordered_map<ll, ll> segCount;
    for (ll i=1;i<=n-1;i++){
        segCount[(i-1)*(n-i)+(n-1)]++;
        segCount[i*(n-i)] += (a[i+1]-a[i]-1);
    }
    segCount[n-1]++;
    for (int i=0;i<q;i++){
        ll seg; cin >> seg;
        cout << segCount[seg] << " ";
    }
    cout << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}