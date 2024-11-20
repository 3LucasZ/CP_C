#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    // cout << n;
    for (int i=1;i<=n;i++){
        if (a[i]==i) continue;
        if (i+1<=n && a[i]==i+1 && a[i+1]==i) {
            i++;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}