#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

vector<int> a;
int n;

vector<int> l;
vector<int> r;

void mn(int x){
    if (x==n) l[x]=1, r[x]=n;
    else {
        l[x] = l[x+1], r[x] = r[x+1];
        while (l[x]<=n && a[l[x]]>x) l[x]++;
        while (r[x]>=1 && a[r[x]]>x) r[x]--;
    }
}
void solve() {
    cin >> n;
    a.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    dbg(n,a);
    
    l.resize(n+1); r.resize(n+1);
    for (int i=n;i>=1;i--) {
        mn(i);
    }
    dbg(l);
    dbg(r);

    //no solution
    for (int i=1;i<=n;i++){
        if (r[i]-l[i]+1>i) {
            cout << 0 << nl;
            return;
        }
    }

    //find intersection
    int sm = a[1]; for (int i=1;i<=n;i++) sm=min(sm,a[i]);
    dbg(sm);
    int l_int = 1; int r_int = n;
    for (int i=sm;i<=n;i++){
        l_int=max(l_int, r[i]-i+1);
        r_int=min(r_int, l[i]+i-1);
    }
    dbg(l_int, r_int);
    cout << r_int-l_int+1 << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}