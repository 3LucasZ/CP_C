#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()


vector<unordered_set<int>> graph;
vector<bool> vis;

void dfs(int node) {
    if (vis[node]) return;
    vis[node] = true;
    for (int child : graph[node]) {
        dfs(child);
    }
}

void solve() {
    dbg();
    int n, m;
    cin >> n >> m;
    graph.clear(); graph.resize(n+1);
    for (int i=0;i<m;i++){
        int u; int v; cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    dbg(graph);
    vector<tuple<int, int, int>> ops;

    // part 1: turn graph into a forest
    for (int u=1;u<=n;u++){
        while (graph[u].size() >= 2) {
            int v1 = *graph[u].begin();
            int v2 = *(++graph[u].begin());
            graph[u].erase(v1); graph[v1].erase(u);
            graph[u].erase(v2); graph[v2].erase(u);
            if (graph[v1].count(v2)) {
                graph[v1].erase(v2); graph[v2].erase(v1);
            } else {
                graph[v1].insert(v2); graph[v2].insert(v1);
            }
            ops.push_back({u, v1, v2});
        }
    }
    dbg(graph);

    // part 2: merge the forest together into one big tree
    bool gone = true;
    for (int i=1;i<=n;i++) {
        if (graph[i].size() > 0) gone = false;
    }
    if (!gone) {
    vector<int> roots;
    vis.clear(); vis.resize(n+1);
    for (int i=1;i<=n;i++){
        if (!vis[i]) {
            roots.push_back(i);
            dfs(i);
        }
    }

    int king1, king2;
    for (int root : roots) {
        if (graph[root].size()>0) {
            king1 = root;
            king2 = *graph[root].begin();
        }
    }
    for (int root : roots) {
        if (root == king1) continue;
        ops.push_back({king1, king2, root});
        king2 = root;
    }
    }

    //ans
    cout << ops.size() << nl;
    for (auto op : ops) {
        int a, b, c; 
        tie(a, b, c) = op;
        cout << a << " " << b << " " << c << nl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}