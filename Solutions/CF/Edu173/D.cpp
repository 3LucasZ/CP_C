#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve() {
    ll L, R, G; cin >> L >> R >> G;
    ll l = (L+G-1)/G;
    ll r = R/G;
    
    for (int gap=0;gap<100;gap++){
        for (int i=0;i<=gap;i++){
            if (l+i<=r-gap+i && gcd(l+i,r-gap+i) == 1) {
                cout << G*(l+i) << " " << G*(r-gap+i) << endl; return;
            }
        }
    }
    cout << -1 << " " << -1 << endl; return;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}