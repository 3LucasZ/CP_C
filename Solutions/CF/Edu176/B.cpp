#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<ll> a(n); 
        for (int i=0;i<n;i++) cin >> a[i];
        
        ll ans = 0;
        if (k==1){
            int tk = 0;
            if (a.back() > a.front()) tk = n-1;
            for (int i=0;i<n;i++){
                if (i==tk) continue;
                ans = max(ans, a[i]);
            }
            cout << ans + a[tk] << nl;;
        } else {
            sort(begin(a),end(a),greater<int>());
            for (int i=0;i<min(k+1, n);i++){
                ans += a[i];
            }
            cout << ans << nl;
        }
    }
}