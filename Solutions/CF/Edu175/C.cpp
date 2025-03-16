#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int n, k;
string s;
vector<int> a;

// can we k-cover a fixed maximum penalty?
// yes -> search lower, no -> search higher
bool search(int mx) {
    int segments = 0;
    bool newSegment = true;
    for (int i=0;i<n;i++){
        if (a[i] > mx) {
            // must be colored
            if (s[i] == 'B') {
                if (newSegment) segments++;
                newSegment = false;
            } 
            // must not be colored
            else {
                newSegment = true;
            }
        }
    }
    // dbg(mx, segments);
    return segments <= k;
}
void solve() {
    cin >> n >> k;
    cin >> s;
    a.clear(); a.resize(n); for (int i=0;i<n;i++) cin >> a[i];
    dbg(n,k,s,a);
    
    int lo = 0; int hi = 1e9;
    while (lo<hi){
        int mid = (lo+hi)/2;
        if (search(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}   