#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n; // # planks
        int k; cin >> k; // # colors
        // color freqs sorted
        vector<ll> a(k); 
        for (int i=0;i<k;i++) cin >> a[i];
        for (int i=0;i<k;i++) a[i]=min(a[i],(ll)n-1); // INSANE EDGE CASE !!!
        sort(begin(a),end(a));
        dbg(a);
        // # colors with = s[i] freq
        vector<ll> s(n+1); 
        int j = k-1; // pointer to current color freq
        for (int i=n;i>=1;i--){ // loop over freq to search on
            while (a[j]==i && j>=0) {
                s[i]++; j--;
            }
        }
        dbg(s);
        // # colors with >= s[i] freq
        for (int i=n-1;i>=0;i--){
            s[i]+=s[i+1];
        }
        dbg(s);
        // # colors with >= s[i] freq + # colors with >= s[i+1] + ...
        for (int i=n-1;i>=0;i--){
            s[i]+=s[i+1];
        }
        dbg(s);

        ll ans = 0;
        for (int i=0;i<k;i++){
            ll matches = s[n-a[i]];
            if (a[i] >= n-a[i]) matches-=(2*a[i]-n+1); // double counting your own color
            ans += matches;
        }
        cout << ans << nl;
    }
}