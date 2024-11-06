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

    int cnt = 0;
    vector<int> a;
    for (int i=0;i<N;i++){
        ans += (i+1);
        if (s[i]=='0') {
            cnt = max(1, cnt+1);
        } else {
            cnt--;
            if (cnt<0) a.push_back(i);
            else ans -= (i+1);
        }
        // dbg(cnt);
    }
    dbg(a);

    for (int i=(a.size()+1)/2;i<a.size();i++){
        ans -= (a[i]+1);
    }
    cout << ans << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}