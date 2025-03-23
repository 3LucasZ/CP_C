#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k;
        int l = 1; int r = n;
        for (int i=0;i<n;i++){
            if (i%k==k-1) {
                cout << l << " ";
                l++;
            } else {
                cout << r << " ";
                r--;
            }
        }
        cout << nl;
    }
}