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
        int a; int b; cin >> a >> b; 
        // int x = max(0,(b-a+1)/2);
        int x = max(0, b - a);
        if (x > a) cout << 0 << nl;
        else cout << a-x << nl;
    }
}