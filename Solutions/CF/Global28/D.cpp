#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve() {
    int n, m; cin >> n >> m;
    n--; int kevin; cin >> kevin; // kevin doesnt count
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> b(m);
    for (int i=0;i<m;i++) cin >> b[i];
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    dbg(n,m,a,b);

    vector<ll> sum(m);
    int j = 0;
    for (int i=0;i<m;i++){
        while (1){
            if (j>=n) break;
            else if (a[j]<b[i]) j++;
            else if (i==m-1) {
                j++; sum[i]++;
            }
            else if (a[j]>=b[i] && a[j]<b[i+1]) {
                j++; sum[i]++;
            } else {
                break;
            }
        }
    }
    // dbg(sum);
    for (int i=m-2;i>=0;i--) {
        sum[i] += sum[i+1];
    }
    // dbg(sum);
    int x=0;
    for (;x<m;x++){
        if (kevin<b[x]) {
            x--;break;
        }
    }
    dbg(kevin, x);

    for (int k=1;k<=m;k++){
        ll ans = 0;
        int unused = m%k;
        for (int l=0;;l+=k){
            int r = l+k-1;
            if (r>=m) break;

            //handle interval (l,r)
            // dbg(l,r);
            ans++;
            if (r<x);
            else if (x<l) ans += sum[l+unused];
            else {
                if (x!=r) {
                    ans += sum[x+unused+1];
                }
            }
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