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
    int n; cin >> n;
    string s; cin >> s;

    // part1
    dbg(s);
    bool flag = false;
    for (int i=0;i<n;i+=2){
        if (flag) {
            s[i] = ')';
            if (s[i+1]==')') flag = false;
        } else {
            s[i] = '(';
            if (s[i+1]=='(') flag = true;
        }
    }
    dbg(s);

    // part2
    ll ans = 0;
    ll open = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '(') {
            open++;
        } else if (s[i] == ')') {
            open--;
        }
        ans += open;
    }
    cout << ans << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}