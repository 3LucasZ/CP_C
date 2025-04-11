#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

vector<vector<int>> g;

pair<int, int> findL(int node, int par, vector<bool>& vis) {
    vis[node] = true;
    //leaf is base case
    if (g[node].size() == 0 || (g[node].size() == 1 && par != 0)) {
        return {1, node};
    }
    //non-leaf
    pair<int, int> ret = {0, 0};
    for (int child : g[node]) {
        if (child != par) ret = max(ret, findL(child, node, vis));
    }
    ret.first ++;
    return ret;
}
void dfs(int node, int par, vector<int>& h, vector<int>& id){
    h[node]=h[par]+1;
    id[node]=id[par];
    for (int child : g[node]){
        if (child!=par) dfs(child, node, h, id);
    }
}
int main() {
    int n, q; 
    cin >> n >> q;
    g.resize(n+1);
    for (int i=0;i<n-3;i++){
        int u, v; 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dbg(g);
    // find L
    vector<int> Ls;
    vector<bool> vis(n+1);
    for (int i=1;i<=n;i++){
        if (!vis[i]) Ls.push_back(findL(i, 0, vis).second);
    }
    dbg(Ls);
    // find R
    vector<int> Rs;
    for (int i=0;i<3;i++){
        Rs.push_back(findL(Ls[i], 0, vis).second);
    }
    dbg(Rs);
    // create Lh
    vector<int> id(n+1);
    vector<int> Lh(n+1);
    for (int i=0;i<3;i++){
        dfs(Ls[i], 0, Lh, id);
    }
    dbg(Lh);
    // create Rh
    vector<int> Rh(n+1);
    for (int i=0;i<3;i++){
        id[0] = i;
        dfs(Rs[i], 0, Rh, id);
    }
    dbg(Rh);
    dbg(id);
    // create diameters of ids
    vector<int> D;
    for (int i=0;i<3;i++){
        D.push_back(Rh[Ls[i]]);
    }
    dbg(D);
    //handle queries
    for (int i=0;i<q;i++){
        int u, v;
        cin >> u >> v;
        int U = max(Lh[u], Rh[u]);
        int V = max(Lh[v], Rh[v]);
        int exclusive = 0^1^2^id[u]^id[v];
        cout << U + V + D[exclusive] << nl;
    }
}