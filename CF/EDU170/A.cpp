#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    string s1, s2; cin >> s1 >> s2;
    int ans = s1.size() + s2.size();
    int save = 0;
    for (int i=0;i<min(s1.size(),s2.size());i++) {
        if (s1[i]==s2[i]){
            save++;
        } else break;
    }
    if (save > 1){
        ans -= (save-1);
    }
    cout << ans << nl;
}
int main() {
    int q; cin >> q;
    for (int i=0;i<q;i++) solve();
}