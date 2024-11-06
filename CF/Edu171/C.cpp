#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int N;
string s;

void solve() {
    cin >> N >> s;
    dbg(N,s);
    ll ans = 0;
    int zeros = 0;  
    for (int i=0;i<N;i++){
        ans += (i+1);
        if (s[i]=='0'){
            zeros++;
        } else {
            if (zeros==0) {
                zeros++;
            } else {
                ans -= (i+1);
                zeros--;
            }
        }
        dbg(i, zeros);
    }
    cout << ans << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}