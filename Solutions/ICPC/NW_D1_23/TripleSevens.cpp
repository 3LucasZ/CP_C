#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    int n; cin >> n;
    bool bad = false;
    for (int i=0;i<3;i++){
        bool seen7 = false;
        for (int j=0;j<n;j++){
            int x; cin >> x;
            if (x==7) seen7 = true;
        }
        if (!seen7) bad = true;
    }
    if (bad) cout << "0" << nl;
    else cout << "777" << nl;
}