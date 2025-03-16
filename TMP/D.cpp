#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

vector<ll> a;
vector<vector<int>> t;

bool ok(int node, ll val) {
    if (val > 1e9) return false;
    if (t[node].size() == 0) {
        return a[node] >= val;
    }
    bool ret = true;
    for (int child : t[node]) {
        if (a[node] >= val) {
            ret &= ok(child, val);
        } else {
            ret &= ok(child, val + val - a[node]);
        }
    }
    return ret;
}

bool ok(ll val) {
    bool ret = true;
    for (int child : t[1]) {
        ret &= ok(child, val);
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    a.clear();a.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    t.clear();t.resize(n+1);
    for (int u=2;u<=n;u++){
        int v; cin >> v;
        t[v].push_back(u);
    }

    ll lo = 0; ll hi = 1e9;
    while (lo < hi) {
        ll mid = (lo + hi + 1)/2;
        if (ok(mid)) {
            lo=mid;
        } else {
            hi=mid-1;
        }
    }
    cout << a[1] + lo << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}