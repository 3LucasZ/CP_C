#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> presum(2*n+1);
    vector<int> cnt(2*n+1);
    for (int i=0;i<n;i++){
        cin >> l[i] >> r[i];
        if (l[i]==r[i]){
            presum[l[i]]=1;
            cnt[l[i]]++;
        }
    }
    for (int i=1;i<=2*n;i++){
        presum[i]+=presum[i-1];
    }
    for (int i=0;i<n;i++){
        if (l[i]!=r[i]){
            int sum = presum[r[i]]-presum[l[i]-1];
            if (sum == r[i]-l[i]+1) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            if (cnt[l[i]]==1){
                cout << 1;
            } else {
                cout << 0;
            }
        }
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}