#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

ll mod = 998244353;
int n;
vector<vector<int>> tree;

vector<vector<int>> layers;
void dfs(int node, int height) {
    if (height >= layers.size()) layers.push_back(vector<int>());
    layers[height].push_back(node);
    for (int child : tree[node]){
        dfs(child, height+1);
    }
}

void solve() {
    cin >> n;
    tree.clear(); tree.resize(n+1);
    for (int v=2;v<=n;v++){
        int u; cin >> u;
        tree[u].push_back(v);
    }
    dbg(tree);

    layers.clear();
    dfs(1, 0);
    dbg(layers);

    vector<ll> dp(n+1);
    ll hdp = 0;

    //base case: last layer have all only 1 path
    for (int node : layers[layers.size()-1]) {
        dp[node] = 1;
        hdp += dp[node];
    }

    //transitions
    for (int i=layers.size()-2;i>=1;i--){
        ll new_hdp = 0;
        for (int node : layers[i]){
            dp[node] = hdp + 1;
            for (int child : tree[node]){
                dp[node] = dp[node] - dp[child];
            }
            dp[node] %= mod;
            new_hdp = new_hdp + dp[node];
        }
        hdp = new_hdp;
    }
    dbg(dp);

    //answer is stored in hdp
    cout << (hdp + 1)%mod << nl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}