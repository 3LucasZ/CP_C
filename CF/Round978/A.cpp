#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve() {
    int n, r; cin >> n >> r;
    vector<int> a;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        a.push_back(x);
    }

    int withFamily = 0;
    int withoutFamily = 0;
    for (int i=0;i<n;i++){
        withFamily += a[i]/2;
        withoutFamily += a[i]%2;
    }
    dbg(n,r,a);
   
    int lonely = 0;
    if (withoutFamily <= (r-withFamily)){
        lonely = withoutFamily;
    } else {
        lonely = 2*(r-withFamily) - withoutFamily;
    }

    cout << 2*withFamily + lonely << nl;
}

int main() {
    int t; cin >> t;
    for (int i=0;i<t;i++) solve();
}