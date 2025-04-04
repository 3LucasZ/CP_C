// https://open.kattis.com/contests/nasouth24d1open/problems
// https://open.kattis.com/contests/nasouth24d1open/problems/trianglesofasquare
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

bool good(int a, int b){
    return (a==0 || a==2024) && (b==0 || b==2024);
}
int main() {
    int x1, y1;
    int x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int ans = 2;
    if (good(x1,y1)) ans--;
    if (good(x2,y2)) ans--;
    cout << ans << nl;
}