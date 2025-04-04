// https://open.kattis.com/contests/nasouth24d1open/problems/herbmixing
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int g, r; 
    cin >> g >> r;
    int ans = 0;
    int p1 = min(g,r);
    ans += 10*p1;
    g-=p1;
    ans += 10*(g/3);
    if (g%3 == 1) ans += 1;
    else if (g%3 == 2) ans += 3;
    cout << ans << nl;
}