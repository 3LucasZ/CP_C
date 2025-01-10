#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    int t; cin >> t; while (t--) {
        int i; int j; cin >> i >> j;
        cout << max(i,j)+1 << nl;
    }
}