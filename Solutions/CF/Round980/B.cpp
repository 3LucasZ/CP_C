#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    int n; int k; cin >> n >> k;
    vector<ll>a(n+1); 
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(begin(a),end(a));
    dbg(n,k,a);

    ll clicks = 0;
    ll have = 0;
    ll base = 0;
    for (int i=1;i<=n;i++){
        a[i]-=base;
        if (a[i]==0) {
            clicks += 1;
            continue;
        }
        base += a[i];
        if (a[i]*(n-i+1)+have >= k){
            clicks += k-have;
            have += k-have;
            break;
        } else {
            clicks += a[i]*(n-i+1);
            have += a[i]*(n-i+1);
            clicks += 1;
        }
    }
    cout << clicks << nl;
}
int main() {
    int t; cin >> t; 
    while (t--)solve();
}