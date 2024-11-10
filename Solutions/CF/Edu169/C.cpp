#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a), greater<ll>());
    for (int i=1;i<n;i+=2){
        ll wantToTake = a[i-1]-a[i];
        ll take = min(wantToTake, k);
        k-=take;
        a[i]+=take;
    }
    dbg(a);

    ll alice = 0;
    for (int i=0;i<n;i+=2){
        alice+=a[i];
    }
    ll bob = 0;
    for (int i=1;i<n;i+=2){
        bob+=a[i];
    }
    dbg(alice, bob);
    cout << alice-bob << nl;
}

int main() {
    int T; cin >> T; while (T--) solve();
}