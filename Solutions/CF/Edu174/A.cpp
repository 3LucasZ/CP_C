#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve() {
    int n; cin >> n;
    vector<int> a(n-2);
    for (int i=0;i<n-2;i++){
        cin >> a[i];
    }
    for (int i=0;i<n-4;i++){
        if (a[i]==1 && a[i+1]==0 && a[i+2]==1){
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}