#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    // sort(all(a));
    for (int i=0;i<n-1;i++){
        if (2*a[i]>a[i+1] && 2*a[i+1]>a[i]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}