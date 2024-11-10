#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int N;
vector<int> a;
vector<ll> whole;
vector<ll> partial;

ll findK (ll x) {
    ll lo=0; ll hi=N;
    while (lo<hi) {
        ll k = lo + ((hi - lo + 1) >> 1);
        if ((2*N-(k-1))*k/2<=x) {
            lo=k;
        } else {
            hi=k-1;
        }
    }
    return lo;
}

ll solve (ll x) {
    ll k = findK(x);
    dbg(x, k);
    return whole[k] + partial[k+1]*x;
}

ll solve(ll l, ll r) {
    dbg(l, r);
    return solve(r) - solve(l-1);
}

int main() {
    cin >> N;
    a.resize(N+1);
    for (int i=1;i<=N;i++) cin >> a[i];
    dbg(N,a);

    whole.resize(N+2);
    for (int i=1;i<=N;i++){
        whole[i] = whole[i-1] + a[i]*((2*N-(i-1))*i)/2;
    }
    dbg(whole);
    partial.resize(N+2);
    for (int i=N;i>=1;i--){
        partial[i] = partial[i+1]+a[i];
    }
    dbg(partial);

    int q; cin >> q;
    for (int i=0;i<q;i++){
        ll l, r; cin >> l >> r;
        cout << solve(l, r) << nl;
    }
}