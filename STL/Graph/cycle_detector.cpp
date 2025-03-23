#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

struct graph {
    int V;
    vector<vector<int>> g;
    vector<int> color;
    graph(int V){
        this->V = V;
        this->g.resize(V);
        this->color.resize(V);
    };
    void add(int u, int v) {
        g[u].push_back(v);
    }
    bool cycle(int u){
        if (color[u]!=0) return false;
        color[u] = 1;
        bool ret = false;
        for (int v : g[u]){
            if (color[v]==2) continue;
            else if (color[v]==0) ret |= cycle(v);
            else ret = true;
        }
        color[u] = 2;
        return ret;
    }
};

int main() {
    graph G = graph(8);
    G.add(0,1);
    G.add(1,2);
    G.add(2,0);
    G.add(3,4);
    G.add(4,5);
    G.add(4,6);
    G.add(4,7);
    cout << G.cycle(0) << nl;
    cout << G.cycle(3) << nl;
}