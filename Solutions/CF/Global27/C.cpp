#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<int> ret;
    int lg = 0; int nn = n; while (nn>0){
        lg++;
        nn/=2;
    }
    // lg = pow(2,lg-1);
    dbg(lg);lg--;
    //2nd half
    unordered_set<int> s;
    for (int i=1;i<=n;i++) s.insert(i);
    vector<int> b;
    for (int i=0;i<lg;i++){
        b.push_back((1<<i));
        s.erase((1<<i));
        if (i==0) {
            b.push_back((1<<lg)-1);
            s.erase((1<<lg)-1);
        }
        else {
            b.push_back((1<<i)+1);
            s.erase((1<<i)+1);
        }
    }
    b.push_back(n);
    s.erase(n);
    //1st half
    vector<int> a;
    for (int x : s) a.push_back(x);
    for (int x : b) a.push_back(x);
    //comp
    int res = 0;
    for (int i=0;i<n;i++){
        if (i%2==0){
            res=res&a[i];
        } else{
            res=res|a[i];
        }
    }
    cout << res << endl;
    for (int x:a){
        cout << x << " ";
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}