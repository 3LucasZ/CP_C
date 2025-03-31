#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int t; cin >> t; while (t--){
        int x,y,a; cin >> x >> y >> a;
        a%=(x+y);
        dbg(x,y,a);
        if (a < x) cout << "NO" << nl;
        else cout << "YES" << nl;
    }
}