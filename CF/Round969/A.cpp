#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int main() {
    int t; cin >> t; 
    while (t--){
        int l; int r; cin >> l >> r;
        if (r-l+1<3) {
            cout << 0 << nl; continue;
        }
        int ans = 0;
        if (l%2==1) {
            l+=3; ans ++;
        }
        ans += (r-l+1)/4;
        cout << ans << nl;
    }
}