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
vector<int> par2;
void DFSpar(int node, int par, vector<vector<int>> &tree, vector<int> &vpar){
    vpar[node]=par;
    for (int child : tree[node]){
        if (child==par) continue;
        DFSpar(child, node, tree, vpar);
    }
}
void DFS(int node, int par) {
    //sorted chs
    vector<int> chs1;
    for (int child : tree1[node]) {
        if (child!=par) chs1.push_back(child);
    }
    sort(all(chs1));

    //iter chs
    for (int ch : chs){
        if (!t2)
        //no grand

        vector<int> gs = tree1[ch]; 
    }
    
    for (int child : tree1[node]){
        if (child==par) continue;
        DFS(child, node);
    }

}

vector<string> tryRoot(int root) {
    par2.clear();par2.resize(N+1);
    DFSpar(root, 0, tree2, par2);

    vector<string> ans;
    DFS(root,0,ans);

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