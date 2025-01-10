#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    for (int r=0;r<2;r++){
        for (int c=0;c<n;c++){
            cin >> a[c][r];
        }
    }
    dbg(a);

    ll realAns = INT_MIN;
    for (int best=0;best<n;best++){
        ll ans = a[best][0]+a[best][1];
        for (int i=0;i<n;i++){
            if (i!=best){
                ans+=max(a[i][0], a[i][1]);
            }
        }
        realAns = max(realAns,ans);
    }
    cout << realAns << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}