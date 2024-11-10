#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
const char nl = '\n';

int N, s, t;
vector<unordered_set<int>> graph;
vector<bool> isNegation;
unordered_set<int> pool;
deque<int> dq;
vector<int> d;

int main() {
    cin >> N >> s >> t;
    graph.resize(N, unordered_set<int>());
    isNegation.resize(N);
    for (int u=0;u<N;u++){
        char type; cin >> type;
        isNegation[u] = type == 'C';
        int m; cin >> m;
        for (int i=0;i<m;i++) {
            int v; cin >> v; 
            graph[u].insert(v);
        }
    }
    dbg(N, s, t);
    dbg(graph);
    dbg(isNegation);

    d.resize(N);
    for (int u=0;u<N;u++) pool.insert(u);
    for (int u=0;u<N;u++) d[u] = -1;
    // s node
    dq.push_back(s); d[s]=0;
    // bfs
    while (dq.size() > 0) {
        int nxt = dq.front(); dq.pop_front();
        if (isNegation[nxt]){
            for (int v : pool) {
                if (d[v] == -1 && !graph[nxt].count(v)){
                    d[v] = d[nxt] + 1;
                    dq.push_back(v);
                }
            }
            pool = graph[nxt];
        } else {
            for (int v : graph[nxt]){
                if (d[v] == -1){
                    d[v] = d[nxt] + 1;
                    dq.push_back(v);
                }
            }
        }
    }
    if (d[t]==-1){
        cout << "impossible" << nl;
    } else {
        cout << d[t] << nl;
    }
}