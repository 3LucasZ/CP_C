#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve() {
    int n, m; cin >> n >> m;
    n--; int kevin; cin >> kevin; // kevin doesnt count
    vector<int> a;
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        if (x>kevin) a.push_back(x); // people worse than kevin have no effect
    }
    n = a.size();
    vector<int> b(m);
    for (int i=0;i<m;i++) {
        int x; cin >> x;
        if (x<=kevin) b[i] = 1e9+1; // problems too easy for kevin -> infinite difficulty
        else b[i] = x;
    }

    // # people who can solve problem i (sorted ascending)
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    dbg(n,m,a,b);
    vector<ll> c(m);
    int j = 0;
    for (int i=0;i<m;i++){
        while (1){
            if (j>=n) break;
            else if (a[j]<b[i]) j++;
            else if (i==m-1) {
                j++; c[i]++;
            }
            else if (a[j]>=b[i] && a[j]<b[i+1]) {
                j++; c[i]++;
            } else {
                break;
            }
        }
    }
    for (int i=m-2;i>=0;i--) {
        c[i] += c[i+1];
    }
    reverse(c.begin(),c.end());
    dbg(c);

    // for interval sized k in [1,m], try to minimize sum of maximum
    for (int k=1;k<=m;k++){
        ll ans = 0;
        for (int i=k-1;i<m;i+=k){
            ans += 1+c[i];
        }
        cout << ans << " ";
    }
    cout << nl;
}
int main() {
    int t; cin >> t; while (t--) {
        solve();
    }
}