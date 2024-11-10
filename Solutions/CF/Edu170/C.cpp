#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

vector<int> cards;
void solve() {
    int n, k; cin >> n >> k;
    cards.resize(n);
    for (int i=0;i<n;i++) cin >> cards[i];
    sort(begin(cards), end(cards));
    dbg(n,k);
    dbg(cards);

    int ans = 0;
    int r=0;
    for (int l=0;l<n;l++){
        r = max(l,r);
        while (r+1<n && cards[r+1]-cards[l]<k && cards[r+1]-cards[r]<=1) r++;
        dbg(l,r);
        ans = max(ans, r-l+1);
    }
    cout << ans << nl;
}

int main() {
    int q; cin >> q;
    for (int i=0;i<q;i++) solve();
}