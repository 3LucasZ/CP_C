#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int n; 
int q; 
vector<int> p;
vector<int> L;
vector<int> mn;
vector<int> mx;

bool isBad(int i) {
    if (i<1 || i>=n) return false;
    if (L[i] && !L[i+1]) {
        if (mx[i]>i || mn[i+1]<i+1) return true;
    }
    return false;
}
void solve (){
    cin >> n >> q;
    p.resize(n+1); for (int i=1;i<=n;i++) cin >> p[i];
    string s; cin >> s;
    L.resize(n+1); for (int i=1;i<=n;i++){
        L[i] = s[i-1]=='L';
    }
    dbg(n,q);dbg(p);dbg(L);

    mx.resize(n+1);
    for (int i=1;i<=n;i++){
        mx[i]=max(mx[i-1],p[i]);
    }
    mn.resize(n+1);
    mn[n] = p[n]; for (int i=n-1;i>=1;i--){
        mn[i]=min(mn[i+1],p[i]);
    }

    unordered_set<int> bad;
    for (int i=1;i<=n-1;i++){
        if (isBad(i)) bad.insert(i);
    }
    for (int i=0;i<q;i++){
        int flip; cin >> flip;
        L[flip] = 1-L[flip];
        if (L[flip]==0){
            bad.erase(flip);
        } 
        if (L[flip]==1) {
            bad.erase(flip-1);
        }
        if (isBad(flip)){
            bad.insert(flip);
        }
        if (isBad(flip-1)){
            bad.insert(flip-1);
        }
        if (bad.size()==0){
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
}

int main() {
    int t; cin >> t; 
    while (t--) solve();
}