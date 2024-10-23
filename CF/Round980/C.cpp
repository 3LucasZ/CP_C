#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin >> a[i][j];
        }
    }
    dbg(n,a);

    sort(all(a), [](vector<int>o1,vector<int>o2){
        int o1mn = min(o1[0],o1[1]);
        int o1mx = max(o1[0],o1[1]);
        int o2mn = min(o2[0],o2[1]);
        int o2mx = max(o2[0],o2[1]);
        if (o1mn==o2mn) return o1mx<o2mx;
        return o1mn<o2mn;
    });
    // sort(all(a), [](vector<int>o1,vector<int>o2){
    //     int p1 = (o1[0]>o2[0])+(o1[0]>o2[1])+(o1[1]>o2[0])+(o1[1]>o2[1]);
    //     int p2 = (o2[0]>o1[0])+(o2[0]>o1[1])+(o2[1]>o1[0])+(o2[1]>o1[1]);
    //     if (p1==p2){
    //         return 
    //     }
    //     return p2>p1;
    // });
    // sort(all(a), [](vector<int>o1,vector<int>o2){
    //     return ((o1[0]<o2[0]) + (o1[0]<o2[1]) + (o1[1]<o2[0]) + (o1[1]<o2[1]));
    // });
    dbg(a);

    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cout << a[i][j] << " ";
        }
    }
    cout << nl;
}
int main() {
    int t; cin >> t; 
    while (t--)solve();
}