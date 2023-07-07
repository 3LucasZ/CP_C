#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const bool multi = false;






/*
Verified: https://cses.fi/problemset/task/1688/
*/
class LCA {
    public:
        vector<vector<int>> tree;
        vector<vector<int>> anc; //[node][2^ith parent]
        vector<int> h;
        int lg;
        LCA(vector<vector<int>> &tree){
            this->tree=tree;
            this->lg=log2(sz(tree));
            h = vector<int>(sz(tree));
            anc = vector<vector<int>>(sz(tree),vector<int>(lg+1));
            fill(1, 0);
        }
        int getAnc(int node, int up){
            if (up > h[node]) return -1;
            int cur = node;
            for (int i=0;i<=lg;i++){
                if (up%2==1) cur=anc[cur][i];
                up = up >> 1;
            }
            return cur;
        }
        int getMax(int u, int v){
            //move to same level: force h[u]<h[v]
            if (h[v]>h[u])swap(u,v);
            u = getAnc(u, h[u]-h[v]);
            if (u==v) return u;
            //lift
            for (int p2=lg;p2>=0;p2--){
                if (anc[u][p2]!=anc[v][p2]){
                    u=anc[u][p2];
                    v=anc[v][p2];
                }
            }
            return anc[u][0];
        }
        void fill(int node, int par){
            h[node]=h[par]+1;
            anc[node][0]=par;
            for (int i=1;i<=lg;i++)anc[node][i]=anc[anc[node][i-1]][i-1];
            for (int child : tree[node]) if (child!=par) fill(child,node);
        }
};





void solve(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> tree(N+1);
    for (int u=2;u<=N;u++){
        int v; cin >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    LCA lca = LCA(tree);
    dbg(N,Q,lca.tree);
    dbg(lca.h);
    dbg(lca.anc);

    for (int i=0;i<Q;i++){
        int u, v; 
        cin >> u >> v;
        cout << lca.getMax(u,v) << nl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}