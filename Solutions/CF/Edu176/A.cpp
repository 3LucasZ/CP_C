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
        int ans = 0;
        if (n%2==1) {
            ans = 1;
            n-=k;
        } 
        if (n>0) {
            k -= k%2;
            ans += (n+k-1)/k;
            cout << ans << nl;
        }
    }
}