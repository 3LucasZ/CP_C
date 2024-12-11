#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

ll MOD = 1e9+7;
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dbg(a);

    vector<ll> sum(n+1);
    for (int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+a[i])%MOD;
    }
    dbg(sum);
    
    vector<ll> d(n+1);
    vector<ll> dsum(n+1);
    vector<ll> p(n+1);
    for (int i=1;i<=n;i++){
        ll x = a[i];
        while (x%2==0){
            p[i]++;
            x/=2;
        }
        d[i]=x;
        dsum[i]=(dsum[i-1]+x)%MOD;
        p[i]=(p[i]+p[i-1])%MOD;
    }
    vector<ll> mx(n+1);
    for (int i=1;i<=n;i++){
        mx[i]=max(mx[i-1],d[i]);
    }
    dbg(d);
    dbg(mx);

    for (int i=1;i<=n;i++){
        cout << max(sum[i], dsum[i]-mx[i]+mx[i]*po(2,p[i])) << " ";
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}