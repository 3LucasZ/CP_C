#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

const ll MOD = 1e9+7;

ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

int main() {
    int q; cin >> q;
    vector<int> a(q);
    vector<int> b(q);
    for (int i=0;i<q;i++) {
        cin >> a[i];
    }
    for (int i=0;i<q;i++) {
        cin >> b[i];
    }
    for (int i=0;i<q;i++){
        cout << po(2,b[i]) << nl;
    }
}