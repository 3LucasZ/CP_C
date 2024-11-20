#include <bits/stdc++.h>
using namespace std;

// void dbg(vector<int> a) {
//     cout << "{";
//     for (int i : a) cout << i << " ";
//     cout << "}";
//     cout << endl;
// }

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    // dbg(a);

    vector<int> mx(n+1);
    for (int i=1;i<=n;i++){
        mx[i] = max(mx[i-1],a[i]);
    }
    // dbg(mx);
    vector<int> mn(n+2, 1e6);
    for (int i=n;i>=1;i--){
        mn[i] = min(mn[i+1],a[i]);
    }
    // dbg(mn);
    vector<int> segs = {1};
    for (int i=2;i<=n;i++){
        if (mx[i-1]>mn[i]) continue;
        segs.push_back(i);
    }
    segs.push_back(n+1);
    // dbg(segs);
    for (int i=0;i<segs.size()-1;i++){
        int l=segs[i];
        int r=segs[i+1]-1;
        int ans = 0;
        for (int j=l;j<=r;j++){
            ans=max(ans,a[j]);
        }
        for (int j=l;j<=r;j++){
            cout << ans << " ";
        }
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}