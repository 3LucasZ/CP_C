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
    for (int i=0;i<n;i++) cin >> a[i];

    deque<int> l;
    vector<int> r; int rmin = INT_MAX;
    for (int i=0;i<n;i++){
        while (!l.empty() && a[i]<l.back()){
            int tmp = l.back(); l.pop_back();
            r.push_back(tmp+1); rmin = min(rmin, tmp+1);
        }
        if (!r.empty() && a[i]>rmin){
            r.push_back(a[i]+1);
        } else {
            l.push_back(a[i]);
        }
    }
    
    sort(all(r));
    dbg(l, r);
    for (int i : l) cout << i << " ";
    for (int i : r) cout << i << " ";
    cout << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}