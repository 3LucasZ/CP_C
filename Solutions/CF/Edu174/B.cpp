#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';


void solve () {
    int R; int C;
    cin >> R >> C;
    vector<vector<int>> a(R, vector<int>(C));
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> a[i][j];
        }
    }
    unordered_set<int> badColors;
    unordered_set<int> totalColors;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            totalColors.insert(a[i][j]);
            if (i+1<R && a[i][j]==a[i+1][j]) {
                badColors.insert(a[i][j]);
            }
            if (j+1<C && a[i][j]==a[i][j+1]) {
                badColors.insert(a[i][j]);
            }
        }
    }
    if (badColors.empty()){
        cout << totalColors.size()-1 << nl;
    } else {
        cout << (badColors.size()-1)*2 + totalColors.size()-badColors.size() << nl;
    }
}
int main() {
    int t; cin >> t; while(t--) solve();
}