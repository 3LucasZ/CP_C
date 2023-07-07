//tags: SegTree, Tree, Max Subarray Sum, Impl, Dual Reuse
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

const bool multi = true;










struct Qry {
    int u, v, k;
};

struct Seg {
    int pre, suf, sum, mx;
    Seg(int x=0){
        sum=x;
        pre=suf=mx=max(x,0);
    }
};
void __print(Seg x) {vector<int> v = {x.pre,x.suf,x.sum,x.mx}; __print(v);}


Seg cmb(Seg& l, Seg& r){
    Seg ret = Seg();
    ret.pre=max(l.pre,r.pre+l.sum);
    ret.suf=max(r.suf,l.suf+r.sum);
    ret.sum=l.sum+r.sum;
    ret.mx=max(max(l.mx, r.mx), l.suf+r.pre);
    return ret;
}

class LCA {
    public:
        vector<vector<int>> tree;
        vector<vector<int>> anc; //[node][2^ith parent]
        vector<vector<Seg>> ancSeg; //[node][node+1 -> 2^ith parent seg]
        vector<int> h;
        vector<int> cost;
        int lg;
        LCA(vector<vector<int>> tree, vector<int> cost){
            this->tree=tree;
            this->cost=cost;
            this->lg=log2(sz(tree));
            h = vector<int>(sz(tree));
            anc = vector<vector<int>>(sz(tree),vector<int>(lg+1));
            ancSeg = vector<vector<Seg>>(sz(tree),vector<Seg>(lg+1));
            fill(1, 0);
        }
        int getAnc(int node, int up, Seg &upd){
            if (up > h[node]) return -1;
            int cur = node;
            for (int i=0;i<=lg;i++){
                if (up%2==1) {
                    upd = cmb(upd,ancSeg[cur][i]);
                    cur=anc[cur][i];
                }
                up = up >> 1;
            }
            return cur;
        }
        int getMax(int u, int v){
            //move to same level: force h[u]<h[v]
            if (h[v]>h[u])swap(u,v);
            Seg uSeg = Seg(cost[u]);
            Seg vSeg = Seg(cost[v]);
            dbg(uSeg);
            u = getAnc(u, h[u]-h[v], uSeg);
            dbg(uSeg);
            if (u==v) return uSeg.mx;
            //lift
            for (int p2=lg;p2>=0;p2--){
                if (anc[u][p2]!=anc[v][p2]){
                    uSeg=cmb(uSeg,ancSeg[u][p2]);
                    vSeg=cmb(vSeg,ancSeg[v][p2]);
                    u=anc[u][p2];
                    v=anc[v][p2];
                }
            }
            int lca = anc[u][0];
            return max(max(uSeg.mx,vSeg.mx),uSeg.suf+vSeg.suf+cost[lca]);
        }
        void fill(int node, int par){
            h[node]=h[par]+1;
            ancSeg[node][0]=Seg(cost[par]);
            anc[node][0]=par;
            for (int i=1;i<=lg;i++){
                ancSeg[node][i]=cmb(ancSeg[node][i-1],ancSeg[anc[node][i-1]][i-1]);
                anc[node][i]=anc[anc[node][i-1]][i-1];
            }
            for (int child : tree[node]) if (child!=par) fill(child,node);
        }
};

void solve(){
    //input, build tree, store queries
    int Q; cin >> Q;
    vector<vector<int>> tree(2);
    vector<int> cost(2); cost[1]=1;
    vector<Qry> queries;
    vector<bool> res;

    for (int i=0;i<Q;i++){
        char type; cin >> type;
        if (type=='+'){
            int u = sz(tree);
            int v, c; 
            cin >> v >> c;
            tree.push_back(vector<int>());
            tree[u].push_back(v);
            tree[v].push_back(u);
            cost.push_back(c);
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            Qry q = Qry(); q.u=u; q.v=v; q.k=k;
            queries.push_back(q);
            res.push_back(true);
        }
    }
    int N = sz(tree)-1;
    dbg(N,tree);
    dbg(cost);
    
    //handle queries
    for (int z=0;z<2;z++){
    LCA lca = LCA(tree, cost);
    dbg("lca init okay");
    for (int i=0;i<sz(queries);i++){
        int u = queries[i].u;
        int v = queries[i].v;
        int k = queries[i].k;
        dbg(u,v,k);
        
        int mx = lca.getMax(u,v);
        dbg(mx);
        if (k > mx) res[i]=false;
        
    }
    //inverse everything for min
    for (int i=0;i<sz(cost);i++) {
        cost[i]*=-1;
    }
    for (int i=0;i<sz(queries);i++) {
        queries[i].k*=-1;
    }
    dbg("REVERSE");
    }

    //ret
    for (bool x : res){
        if (x) cout << "YES";
        else cout << "NO";
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}