#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

ll inf = 1e18;

int n;
vector<ll> a;
vector<int> b;
vector<vector<pair<int,int>>> graph;

void solve() {
    cin >> n;
    a.clear(); a.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    b.clear(); b.resize(n+1);
    for (int i=1;i<=n;i++) cin >> b[i];

    graph.clear(); graph.resize(n+1);
    for (int i=1;i<=n;i++){
        graph[i].push_back({b[i], a[i]});
        graph[i].push_back({i-1, 0});
    }
    dbg(graph);

    vector<ll> dist(n+1, inf);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist[1]=0;

    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (auto i : graph[u]) {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    dbg(dist);
    
    vector<ll> sum(n+1);
    for (int i=1;i<=n;i++){
        sum[i] = sum[i-1] + a[i];
    }
    dbg(sum); 

    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, sum[i]-dist[i]);
    }
    cout << ans << nl;
}
int main() {
    int t; cin >> t; 
    while (t--)solve();
}