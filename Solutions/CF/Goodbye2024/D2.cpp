#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

const ll MOD = 998244353;
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}
ll inv(ll x) {
    return po(x,MOD-2);
}
 
void solve() {
    int n, q; 
    cin >> n >> q;
    vector<ll> a(n); vector<ll> as(n);
    vector<ll> b(n); vector<ll> bs(n);
    for (int i=0;i<n;i++) {cin >> a[i]; as[i] = a[i];} 
    for (int i=0;i<n;i++) {cin >> b[i]; bs[i] = b[i];}
    sort(all(as));
    sort(all(bs));

    ll ans = 1;
    for (int i=0;i<n;i++) ans = (ans * min(as[i],bs[i]))%MOD;
    cout << ans << " ";
    for (int i=0;i<q;i++){
        int o, x;
        cin >> o >> x; x--;
        if (o==2) {
            swap(a,b);
            swap(as,bs);
        }
        int lo = 0; int hi = n-1;
        while (lo < hi) {
            int mid = (lo + hi + 1)/2;
            if (as[mid] <= a[x]) lo = mid;
            else hi = mid-1;
        }
        ans = (ans * inv(min(a[x],bs[lo]))) % MOD;
        ans = (ans * min(a[x]+1,bs[lo])) % MOD;
        a[x]++;
        as[lo]++;
        if (o==2) {
            swap(a,b);
            swap(as,bs);
        }
        cout << ans << " ";
    }
    cout << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}