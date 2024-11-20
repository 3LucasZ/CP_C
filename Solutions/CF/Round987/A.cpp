#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int best=0;
    int streak=0;
    int last = -1;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        if (x==last) streak++;
        else streak=1;
        best=max(best,streak);
        last = x;
    }
    cout << n-best << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}