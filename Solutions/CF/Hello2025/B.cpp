#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(all(a));
    vector<int> cnts = {1};
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) cnts.back()++;
        else cnts.push_back(1);
    }
    sort(all(cnts));
    int ans = cnts.size();
    for (int i : cnts){
        k-=i;
        if (k<0) break;
        ans--;
    }
    cout << max(1,ans) << nl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) {
        solve();
    }
}