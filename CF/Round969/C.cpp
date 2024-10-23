#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end()

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int t; cin >> t; 
    while (t--){
        int n; int a; int b; 
        cin >> n >> a >> b;
        int gc = gcd(a,b);
        vector<int> c(n);
        for (int i=0;i<n;i++) {
            cin >> c[i]; c[i]%=gc;
        }
        sort(all(c)); 
        int ans = c[n-1]-c[0];
        for (int i=0;i<n-1;i++){
            ans = min(ans, c[i]+gc-c[i+1]);
        }
        cout << ans << nl;
    }
}