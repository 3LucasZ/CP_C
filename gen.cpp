#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    freopen("in.txt","w",stdout);
    int t = 5;
    cout << t << endl;
    for (int i=0;i<t;i++){
        ll n = 1e5;
        ll k = 1e5;
        cout << n << " " << k << endl;
        int x = 1e9;
        for (int i=0;i<n;i++) {
            cout << x-i << endl;
        }
    }
}