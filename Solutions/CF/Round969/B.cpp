#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int main() {
    int t; cin >> t; 
    while (t--){
        int n; int m; cin >> n >> m;
        int one = -1e9;
        int two = -1e9;
        for (int i=0;i<n;i++){
            int x; cin >> x;
            if (x >= one){
                two = one;
                one = x;
            }
        }
        for (int i=0;i<m;i++){
            char op; int l; int r; cin >> op >> l >> r;
            int d = op == '+' ? 1 : -1;
            if (l <= one && one <= r) one+=d;
            if (l <= two && two <= r) two+=d;
            cout << max(one, two) << " ";
        }
        cout << nl;
    }
}