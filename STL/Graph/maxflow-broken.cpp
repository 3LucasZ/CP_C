#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

class Edge {
    public:
        int u;
        int v;
        ll cap;
        Edge* residual;
        bool orig;

        Edge(int u, int v, int c, bool o) : u(u), v(v), cap(c), orig(o) {}

        void augment(ll pathCap){
            cap -= pathCap;
            residual->cap += pathCap;
        }
};

class MaxFlow {
/*
Conditions:
directed graph
1 indexed graph
list storage
*/
    public:
        int N;
        int S;
        int T;
        vector<vector<Edge>> graph;
        vector<bool> visited;

        const ll INF=1e18;

        MaxFlow(int N,int S,int T): N(N), S(S), T(T) {
            graph.resize(N+1);
            visited.resize(N+1);
        }

        void addEdge(int u, int v, ll c){
            Edge forward(u,v,c,true);
            Edge residual(v,u,0,false);
            graph.at(u).push_back(forward);
            graph.at(v).push_back(residual);
            forward.residual = &residual;
            residual.residual = &forward;
        }

        ll solve(){
            ll maxFlow = 0;
            ll flow = 0;
            while(true){
                visited.clear(); visited.resize(N+1);
                flow = dfs(S, INF);
                if (flow == 0) break;
                maxFlow += flow;
            }
            return maxFlow;
        }

        ll dfs(int node, ll flow){
            //found augmenting path
            if(node == T) return flow;
            visited.at(node) = true;
            for(Edge& child : graph.at(node)){
                if(child.cap > 0 && !visited.at(child.v)){
                    ll pathCap = dfs(child.v, min(flow, child.cap));
                    //augmenting path exists
                    if(pathCap > 0){
                        child.augment(pathCap);
                        return pathCap;
                    }
                }
            }
            return 0;
        }
};



int main() {
    int N, M;
    cin >> N >> M; 
    MaxFlow mf(N, 1, N);
    for (int i=0;i<M;i++){
        int u, v, c; cin >> u >> v >> c;
        mf.addEdge(u,v,c);
    }
    ll ans = mf.solve();
    cout << ans << nl;
    return 0;
}