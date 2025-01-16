#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i]!=1 && a[i]!=-1) x = i;
    }
    // dbg(a, x);
    int lmin = 0; int lmax = 0; int lminf = 0; int lmaxf = 0;
    for (int i=0;i<x;i++){
        lminf = min(0, lminf+a[i]);
        lmaxf = max(0, lmaxf+a[i]);
        lmin = min(lmin, lminf);
        lmax = max(lmax, lmaxf);
    }
    int rmin = 0; int rmax = 0; int rminf = 0; int rmaxf = 0;
    for (int i=n-1;i>x;i--){
        rminf = min(0, rminf+a[i]);
        rmaxf = max(0, rmaxf+a[i]);
        rmin = min(rmin, rminf);
        rmax = max(rmax, rmaxf);
    }
    vector<int> ans;
    for (int i=lmin;i<=lmax;i++) ans.push_back(i);
    for (int i=rmin;i<=rmax;i++) ans.push_back(i);
    for (int i=lminf+rminf;i<=lmaxf+rmaxf;i++) ans.push_back(a[x]+i);
    sort(all(ans));
    // dbg(ans);
    vector<int> ans2;
    ans2.push_back(ans[0]);
    for (int i=1;i<ans.size();i++){
        if (ans[i]!=ans[i-1]) ans2.push_back(ans[i]);
    }
    cout << ans2.size() << endl;
    for (int i : ans2) cout << i << " ";
    cout << endl;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}