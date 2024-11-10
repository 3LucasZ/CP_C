#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int N;
vector<ll> a;

bool solve(ll K) {
    int cluster = 0;
    int single = 0;
    int paired = 0;
    for (int i=0;i<N;i++){
        cluster++;
        if (i==N-1 || a[i+1]-a[i]>K) {
            if (cluster%2==1) single++;
            paired += cluster/2;
            cluster = 0;
        }
    }
    return single <= 1;
    // return paired >= single;
}

void solve() {
    cin >> N;
    a.resize(N);
    for (int i=0;i<N;i++) cin >> a[i];
    dbg(N,a);
    if (N==1) {
        cout << 1 << nl; return;
    }

    ll ans = 1e18;
    for (int i=1;i<N;i++){
        ll K = a[i]-a[i-1];
        if (solve(K)) {
            ans = min(ans, K);
        }
    }
    cout << ans << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}