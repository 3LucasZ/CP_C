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
        string a; cin >> a;
        bool seen = false;
        for (int i=0;i<n-1;i++){
            if (a[i]=='1' && a[i+1]=='1'){
                seen = true;
            }
        }
        if (seen || a[0]=='1' || a[n-1]=='1'){
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
}