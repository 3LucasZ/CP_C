#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

ll solve() {
    ll n, m, v;
    cin >> n >> m >> v;
    vector<ll> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dbg(n,m,v);
    dbg(a);

    vector<int> l; l.push_back(0);
    ll tot = 0;
    for (int i=1;i<=n;i++){
        tot += a[i];
        if (tot>=v){
            l.push_back(i);
            tot = 0;
        }
    }
    dbg(l);

    vector<int> r; r.push_back(n+1);
    tot = 0;
    for (int i=n;i>=1;i--){
        tot += a[i];
        if (tot>=v){
            r.push_back(i);
            tot = 0;
        }
    }
    dbg(r);

    vector<ll> sum(n+1);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    dbg(sum);
    
    ll mx = -1;
    for (int i=0;i<=m;i++){
        if (m-i >= r.size() || i >= l.size()) continue;
        mx = max(mx, sum[r[m-i]-1]-sum[l[i]+1 -1]);
    }
    return mx;
}
int main() {
    int t; cin >> t;
    while (t--) cout << solve() << nl;
}