#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int n = s.size();
        cout << 1 << " " << n << " ";
        int ones = 0;
        int zeros = 0;
        for (int i=0;i<n;i++){
            if (s[i]=='1') {
                if (zeros > 0) break;
                ones++;
            }
            else {
                zeros++;
            }
        }
        // dbg(s,ones,zeros);
        if (zeros==0) cout << 1 << " " << 1 << nl;
        else {
                int l = max(1, ones+1-zeros);
                int r = l+(n-(ones+1));
                cout << l << " " <<  r << nl;
        }
    }
}