#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve() {
    int r; int c;
        cin >> r >> c;
        vector<vector<int>> a(r, vector<int>(c));
        for (int i=0;i<r;i++){
            string s;
            cin >> s;
            for (int j=0;j<c;j++){
                a[i][j] = s[j]-'0';
            }
        }
        dbg(a);

        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (a[i][j] == 0) continue;
                int cnt = 0;
                for (int k=i-1;k>=0;k--){
                    if (a[k][j] == 0) {
                        cnt++;
                        break;
                    }
                }
                for (int k=j-1;k>=0;k--){
                    if (a[i][k] == 0) {
                        cnt++;
                        break;
                    }
                }
                if (cnt >= 2) {
                    cout << "NO" << nl;
                    return;
                }
            }
        }
        cout << "YES" << nl;
}
int main() {
    int t; cin >> t; while (t--){
        solve();
    }
}