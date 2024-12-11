#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    if (n%2==0) {
        for (int i=0;i<n-2;i++){
            cout << 3;
        }
        cout << "66";
    }
    else {
        if (n==1 || n==3) {
            cout << -1;
        }
        else {
            for (int i=0;i<n-4;i++){
                cout << 3;
            }
            cout << "6366";
        }
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}