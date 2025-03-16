#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';


void solve() {
    int n; cin >> n;
    vector<vector<bool>> ok(2, vector<bool>(n));
    for (int i=0;i<2;i++){  
        string s; cin >> s;
        for (int j=0;j<n;j++){
            ok[i][j] = (s[j] == '.');
        }
    }
    dbg(ok);
    
    int ans = 0;
    for (int i=0;i<2;i++){
        for (int j=1;j<=n-2;j++){
            if (ok[i][j-1] && !ok[1-i][j-1] &&
                ok[i][j] && ok[1-i][j] && 
                ok[i][j+1] && !ok[1-i][j+1]) {
                    ans ++;
                }
        }
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}