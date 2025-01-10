#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    int sum = 0;
    int ans = 0;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        sum += a;
        int rt = sqrt(sum);
        if (rt*rt == sum && rt%2==1) ans++;
    }
    cout << ans << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}