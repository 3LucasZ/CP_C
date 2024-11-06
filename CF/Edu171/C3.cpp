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
    
    deque<int> zeros;
    int ones = 0;
    ll ans = 0;

    for (int i=0;i<N;i++){
        if (s[i]=='0') zeros.push_front(i);
        else ones++;
        ans += (i+1);
    }
    dbg(ones, zeros);

    for (int i=N-1;i>=0;i--){
        if (s[i]=='0') {
            if (zeros.front() == i) zeros.pop_front();
        } else {
            ones--;
            if (zeros.size()>0) {
                zeros.pop_front();
                ans-=(i+1);
            } else {
                if (ones>0) {
                    ones--;
                    ans-=(i+1);
                } else {
                    break;
                }
            }
        }
        dbg(ones, zeros);
    }

    cout << ans << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}