#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    int N, K; cin >> N >> K;
    vector<ll> a(N);
    for (int i=0;i<N;i++){
        cin >> a[i];
    }
    
    ll sum = 0; 
    for (int i=0;i<N;i++) sum+=a[i];

    ll mx = 0;
    for (int i=0;i<N;i++) mx=max(mx, a[i]);

    ll m = (K-sum%K)%K;
    dbg(N, K, sum, mx, m);

    for (int c=0;c<=25000000;c++){
        dbg(c);
        ll l = max(K*(mx+c)-sum, 0LL);
        if (l < 0) continue;
        ll r = (N*mx-sum+c*N);
        dbg(l, r);
        ll lu = (l/K)*K + m;
        while (lu < l) lu += K;
        ll rd = ((l+K-1)/K)*K + m;
        while (rd > r) rd -= K;
        if (lu <= rd) {
            cout << lu << nl;
            break;
        }
    }
}