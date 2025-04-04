// https://open.kattis.com/contests/nasouth24d1open/problems/duelofcards
// https://open.kattis.com/problems/duelofcards
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    vector<bool> seen(2*n+1);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        seen[a[i]] = true;
    }
    for (int i=1;i<=2*n;i++) {
        if (!seen[i]) b.push_back(i);
    }
    sort(begin(a),end(a));
    sort(begin(b),end(b));

    for (int z=0;z<2;z++){
        swap(a,b);
        int j=0;
        int ans=0;
        for (int i=0;i<n;i++){
            if (a[i] > b[j]) {
                ans++;
                j++;
            }
        }
        if (z==0) cout << n-ans << " ";
        else cout << ans << nl;
    }
}