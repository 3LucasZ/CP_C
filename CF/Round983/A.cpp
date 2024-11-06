#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int N; cin >> N;
    int zeros = 0;
    for (int i=0;i<2*N;i++){
        int x; cin >> x;
        if (x == 0) zeros++;
    }
    int ones = 2*N-zeros;
    dbg(2*N, zeros, ones);

    cout << N-zeros/2-ones/2 << " ";
    cout << min(zeros, ones) << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}