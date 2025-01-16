#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    ll n; cin >> n;
    ll mult = 1;
    while (n>3) {
        n/=4;
        mult*=2;
    }
    cout << mult << endl;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}