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
        int n; cin >> n;
        int mn = 1000;
        int mx = 0;
        for (int i=0;i<n;i++){
            int x; cin >> x;
            mn=min(x,mn);
            mx=max(x,mx);
        }
        cout << (mx-mn)*(n-1) <<nl;
    }
}