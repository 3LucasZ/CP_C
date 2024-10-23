#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

map<string, int> cvt;



void solve() {
    int n, q; cin >> n >> q;
    vector<string> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dbg(n,q,a);

    vector<vector<int>> l(n+1, vector<int>(7, -1e8));
    for (int i=2;i<=n;i++){
        for (int u=1;u<=6;u++){
            if (u!=cvt[a[i-1]] && u+cvt[a[i-1]]!=7) l[i][u]=i-1;
            else l[i][u]=l[i-1][u];
        }
    }
    vector<vector<int>> r(n+1, vector<int>(7, 1e8));
    for (int i=n-1;i>=1;i--){
        for (int u=1;u<=6;u++){
            if (u!=cvt[a[i+1]] && u+cvt[a[i+1]]!=7) r[i][u]=i+1;
            else r[i][u]=r[i+1][u];
        }
    }
    for (int i=0;i<=n;i++){
        dbg(l[i]);
    }
    for (int i=0;i<=n;i++){
        dbg(r[i]);
    }

    for (int i=0;i<q;i++){
        int u; int v; cin >> u >> v;
        int uType = cvt[a[u]]; int vType = cvt[a[v]];
        if (uType + vType == 7){
            int goLeft = abs(u-l[u][uType])+abs(v-l[u][uType]);
            int goRight = abs(u-r[u][uType])+abs(v-r[u][uType]);
            if (min(goLeft, goRight) > 1e6) cout << -1 << nl;
            else cout << min(goLeft, goRight) << nl;
        } else {
            cout << abs(v-u) << nl;
        }
    }
}

int main() {
    cvt["BG"] = 1;
    cvt["BR"] = 2;
    cvt["BY"] = 3;
    cvt["RY"] = 6;
    cvt["GY"] = 5;
    cvt["GR"] = 4;
    int T; cin >> T; while (T--) solve();
}