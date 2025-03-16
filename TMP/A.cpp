#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

char no(char x) {
    return 'a'+(x-'a'+1)%26;
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    bool done = false;
    for (int i=0;i<n;i++){
        if (i>0 && s[i]==s[i-1] && !done) {
            cout << no(s[i]);
            done = true;
        }
        cout << s[i];
    }
    if (!done) cout << no(s[n-1]);
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}