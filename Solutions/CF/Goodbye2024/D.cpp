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
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        cin >> b[i];
    }

    vector<int> a_oti(n); // oti = ord_to_id
    for (int i=0;i<n;i++) a_oti[i]=i;
    sort(all(a_oti),[&](int i, int j){
        return a[i]<a[j];
    });
    vector<int> a_ito(n);// ito = id_to_ord
    for (int i=0;i<n;i++) a_ito[a_oti[i]]=i;

    vector<int> b_oti(n);
    for (int i=0;i<n;i++) b_oti[i]=i;
    sort(all(b_oti),[&](int i, int j){
        return b[i]<b[j];
    });
    vector<int> b_ito(n);
    for (int i=0;i<n;i++) b_ito[b_oti[i]]=i;

    dbg(a,b);
    dbg(a_oti,b_oti);
    dbg(a_ito,b_ito);

    ll ans = 1;
    for (int i=0;i<n;i++){
        ans = (ans * min(a[a_oti[i]] ,b[b_oti[i]]))%MOD;
    }
    cout << ans << " ";
    for (int i=0;i<q;i++){
        int o, x;
        cin >> o >> x; x--;
        if (o==2) {
            swap(a,b);
            swap(a_oti,b_oti);
            swap(a_ito,b_ito);
        }
        int x_ord = a_ito[x];
        dbg(x_ord);
        ans = (ans * inv(min(a[a_oti[x_ord]],b[b_oti[x_ord]]))) % MOD;
        if (x_ord<n-1) ans = (ans * inv(min(a[a_oti[x_ord+1]],b[b_oti[x_ord+1]]))) % MOD;
        a[x]++;
        if (x_ord<n-1 && a[a_oti[x_ord]] > a[a_oti[x_ord+1]]) {
            swap(a_ito[a_oti[x_ord]], a_ito[a_oti[x_ord+1]]);
            swap(a_oti[x_ord], a_oti[x_ord+1]);
        }
        ans = (ans * min(a[a_oti[x_ord]],b[b_oti[x_ord]])) % MOD;
        if (x_ord<n-1) ans = (ans * min(a[a_oti[x_ord+1]],b[b_oti[x_ord+1]])) % MOD;
        if (o==2) {
            swap(a,b);
            swap(a_oti,b_oti);
            swap(a_ito,b_ito);
        }
        cout << ans << " ";
        dbg(a,b);
        dbg(a_oti,b_oti);
        dbg(a_ito,b_ito);
    }
    cout << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}