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
    //pt1
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dbg(a);

    //pt2
    vector<int> p(n+1);
    for (int i=1;i<=n;i++){
        while (a[i]%2==0){
            p[i]++;
            a[i]/=2;
        }
    }
    dbg(a);
    dbg(p);

    //pt3
    stack<ll> s;
    vector<ll> r(n+1);
    for (int i=1;i<=n;i++){
        while (!s.empty() && a[i]>=a[s.top()]){
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    dbg(r);
    vector<vector<int>> l(n+1);
    for (int i=1;i<=n;i++){
        l[r[i]].push_back(i);
    }
    dbg(l);

    //pt4
    ll sum = 0;
    for (int i=1;i<=n;i++){        
        //remove old p[i]
        for (int mv : l[i]){
            sum-=(a[mv]*po(2,p[mv]));
            sum+=a[mv];
            p[i]+=p[mv];
        }
        //upd sum
        sum+=(a[i]*po(2,p[i]));
        cout << sum << " ";
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}