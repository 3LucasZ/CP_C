#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int n;
vector<vector<int>> tree;
void solve() {
    cin >> n;
    tree.clear(); tree.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<bool> isLeaf(n+1);
    for (int i=1;i<=n;i++) isLeaf[i] = tree[i].size()==1;
    vector<int> adjLeaves(n+1);
    for (int i=1;i<=n;i++) for (int j : tree[i]) adjLeaves[i] += isLeaf[j];
    
    dbg(n,tree);
    dbg(isLeaf);
    dbg(adjLeaves);

    ll ans = 0;
    //part 1
    ll leaves = 0;
    for (int i=1;i<=n;i++) if (isLeaf[i]) leaves++;
    ans = leaves*(n-leaves);
    //part 2
    int qCnt = 0;
    for (int q=1;q<=n;q++){
        if (isLeaf[q]) continue;
        if (adjLeaves[q]>0) continue;
        qCnt++;
    }
    //loop thru p2
    for (int p2=1;p2<=n;p2++){
        if (adjLeaves[p2]==0) continue;
        ans += qCnt * (tree[p2].size()-1-adjLeaves[p2]);
    }
    cout << ans << nl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}