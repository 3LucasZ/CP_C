#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int, int> pi;
//typedef pair<ll, ll> pll;

#define sz(x) (int)(x).size()
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
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

const ll MOD = 1e9+7;
const bool multi = true;




class DSU {
    public:
        int sz;
        vector<int> par;
        vector<int> csz;

        DSU(int sz){
            this->sz=sz;
            par = vector<int>(sz+1,-1);
            csz = vector<int>(sz+1,1);
        }

        int getPar(int v){
            if (par[v] == -1) {
                return v;
            }
            par[v] = getPar(par[v]);
            return par[v];
        }

        void join(int u, int v){
            int U = getPar(u);
            int V = getPar(v);
            //same c, do nothing
            if (U == V) return;
            //force csz[V]<csz[U]
            if (csz[U]<csz[V])swap(U,V);
            //op
            par[V] = U;
            csz[U] += csz[V];
        }
        //chex CC
        bool connected(int u, int v){
            return getPar(u)==getPar(v);
        }
    };
void __print(DSU x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.getPar(i)); __print(v);}


int N,M;
vector<vector<int>> tree1;
vector<vector<int>> tree2;
vector<int> par1;
vector<int> par2;
vector<int> nodeDepth1;
vector<int> nodeDepth2;
vector<unordered_set<int>> layer1;
vector<unordered_set<int>> layer2;

void DFS(vector<vector<int>> &tree, vector<int> &nodeDepth, vector<int> &vpar, int node, int par) {
    nodeDepth[node]=nodeDepth[par]+1;
    vpar[node]=par;
    for (int child : tree[node]){
        if (child==par) continue;
        DFS(tree, nodeDepth, vpar, child, node);
    }
}
void merge(vector<vector<int>> tree, int u, int v){
    //sz[U] > sz[V], child[V]->add->child[U]->fix->child[max(u,v)]
    int U = u; int V = v;
    if (sz(tree[u]) < sz(tree[v])) swap(U,V);
    for (int x : tree[V]) {
        tree[U].push_back(x);
    }
    tree[max(u,v)]=tree[U];
    tree[min(u,v)].clear();
}
vector<string> tryRoot(int root) {
    dbg(root);
    //find depth[x],par[x]. partition tree into layers. for both trees.
    nodeDepth1.clear();nodeDepth1.resize(N+1);
    nodeDepth2.clear();nodeDepth2.resize(N+1);
    par1.clear();par1.resize(N+1);
    par2.clear();par2.resize(N+1);
    DFS(tree1, nodeDepth1, par1, root, 0);
    DFS(tree2, nodeDepth2, par2, root, 0);
    for (int i=1;i<=N;i++){
        if (nodeDepth2[i]!=0 && nodeDepth2[i]!=nodeDepth1[i]) return vector<string>(0);
    }
    layer1.clear();layer1.resize(N+1);
    layer2.clear();layer2.resize(N+1);
    for (int i=1;i<=N;i++){
        layer1[nodeDepth1[i]].insert(i);
        if (nodeDepth2[i]!=0) layer2[nodeDepth2[i]].insert(i);
    }
    dbg(par1);
    dbg(par2);
    vector<string> ans;
    DSU dsu(N);
    
    //if par1[x]!=par2[x] then merge par1[x], par2[x]
    for (int layer=1;layer<N;layer++){
        dbg(layer);

        //delete leaves on tree1 to match tree2 
        for (int node : layer1[layer]){
            int mx = 0;
            for (int child : tree1[node]){
                if (child==dsu.getPar(par1[child])) continue;
                mx=max(mx,child);
            }
            for (int child : tree1[node]){
                if (child==dsu.getPar(par1[child])) continue;
                if (!layer2[layer+1].count(child)) {
                    if (mx > child){
                        dbg(mx,child);
                        ans.push_back(to_string(mx)+" "+to_string(child));
                    } else {
                        return vector<string>(0);
                    }
                }
            }
        }

        for (int x : layer1[layer+1]){
            if (par1[x]!=par2[x]&&par2[x]!=0){
                dbg(x,par1[x],par2[x]);
                merge(tree1,par1[x],par2[x]);
                ans.push_back(to_string(par1[x])+" "+to_string(par2[x]));
            }
        }
    }

    return ans;
}
void solve(){
    //in
    cin >> N;
    tree1.clear(); tree1.resize(N+1); 
    for (int i=0;i<N-1;i++){
        int u, v;
        cin >> u >> v;
        tree1[u].push_back(v);
        tree1[v].push_back(u);
    }
    dbg(N,tree1);
    cin >> M;
    tree2.clear(); tree2.resize(N+1);
    for (int i=0;i<M-1;i++){
        int u, v;
        cin >> u >> v;
        tree2[u].push_back(v);
        tree2[v].push_back(u);
    }
    dbg(M,tree2);

    //p1: N-M
    cout << N-M << nl;

    //tests
    // tryRoot(1);
    // dbg(nodeDepth1);
    // dbg(nodeDepth2);
    // dbg(par1);
    // dbg(par2);
    // dbg(layer1);
    // dbg(layer2);


    //p2: bash roots
    for (int i=1;i<=N;i++){
        vector<string> ans = tryRoot(i);
        if (sz(ans)!=0){
            dbg(i);
            for (string x : ans) cout << x << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) {
        dbgM(i+1);
        solve();
    }
    return 0;
}