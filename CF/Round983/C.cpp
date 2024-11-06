#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;i++) cin >> a[i];
    sort(all(a));
    dbg(N, a);

    int best = 0;
    int r = 0;
    for (int i=0;i<N;i++){
        while (r < N && a[i]+a[i+1]>a[r]) r++;
        best = max(best, r-i);
    }
    cout << N-best << nl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}