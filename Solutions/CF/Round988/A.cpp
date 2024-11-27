#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n+1);
    for (int i=0;i<n;i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int i=0;i<=n;i++){
        ans+=cnt[i]/2;
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}