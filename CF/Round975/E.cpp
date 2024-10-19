#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int n;
vector<vector<int>> tree;
vector<int> l; //height
vector<int> r; //child's max height

void dfs(int node, int par){
    l[node]=l[par]+1;
    r[node]=l[node];
    for (int child : tree[node]){
        if (child==par) continue;
        dfs(child, node);
        r[node] = max(r[node], r[child]);
    }
}

void solve() {
    cin >> n;
    tree.clear(); tree.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dbg(n, tree);

    l.resize(n+1);
    r.resize(n+1);
    dfs(1,0);
    dbg(l);
    dbg(r);
    
    vector<int> cost(n+2);
    cost[0]=n;
    for (int node=1;node<=n;node++){
        cost[l[node]]--;
        cost[r[node]+1]++;
    }
    for (int i=1;i<=n;i++){
        cost[i]+=cost[i-1];
    }
    int ans = 1000000;
    for (int i=1;i<=n;i++){
        ans = min(ans,cost[i]);
    }
    cout << ans << nl;
}

int main() {
    int t; cin >> t; while (t--) solve();
}