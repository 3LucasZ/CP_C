#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int N;
vector<int> a;
vector<ll> p;
vector<ll> pi;
ll sum(int i, int j) {
    return (j+1)*(p[j]-p[i-1]) - (pi[j]-pi[i-1]);
}
vector<ll> s;

int findK (ll x) {
    ll lo=0; ll hi=N;
    while (lo<hi) {
        ll k = lo + ((hi - lo + 1) >> 1);
        if ((2*N-k+1)*k/2<x) {
            lo=k;
        } else {
            hi=k-1;
        }
    }
    return lo;
}
ll handle(ll x) {
    int k = findK(x);
    ll i = (ll)(2*N-k+1)*k/2+1;
    return s[k] + sum(k+1, k+1+(x-i));
}
ll handle(ll l, ll r) {
    return handle(r)-handle(l-1);
}

void solve() {
    cin >> N;
    a.resize(N+1); p.resize(N+1); pi.resize(N+1);
    for (int i=1;i<=N;i++) {
        cin >> a[i];
        p[i] = p[i-1] + a[i];
        pi[i] = pi[i-1] + i*a[i];
    }
    dbg(N, a);
    dbg(p);
    dbg(pi);

    s.resize(N+1);
    for (int i=1;i<=N;i++){
        s[i] = s[i-1] + sum(i, N);
    }
    dbg(s);

    int q; cin >> q;
    for (int i=0;i<q;i++){
        ll l, r; cin >> l >> r;
        cout << handle(l, r) << nl;
    }

}
int main() {
    solve();
}