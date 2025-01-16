#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n, d; cin >> n >> d;
    vector<int> xs = {1,3,5,7,9};
    int n2 = min(n, 3);
    int r = 1;
    while (n2 > 1) {
        r *= n2; n2--;
    }
    int q = 0;
    while (r > 0) {
        q = 10*q + d; r--;
    }
    dbg(q);
    for (int x : xs) {
        if (q%x==0 || (x==9 && n >= 6)) cout << x << " ";
    }
    cout << endl;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}