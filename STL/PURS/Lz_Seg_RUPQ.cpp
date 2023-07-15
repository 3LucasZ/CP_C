#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int)(x).size()
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

class SegTree {
    ll op(ll a, ll b){
        if (b==NO_OP) return a;
        return b;
    }
    public:
        int sz;
        vector<ll> tree;
        ll NO_OP = LLONG_MAX;

        SegTree(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree = vector<ll>(2*sz+1,0);
        }
        void push_down(int x, int lx, int rx) {
            if (lx==rx) return;
            tree[2*x]=op(tree[2*x],tree[x]);
            tree[2*x+1]=op(tree[2*x+1],tree[x]);
            tree[x] = NO_OP;
        }
        void update (int l, int r, int v){update(l,r,v,1,1,sz);}
        void update(int l, int r, int v, int x, int lx, int rx) {
            push_down(x,lx,rx);
            if (lx>r || rx<l) return; //seg out
            else if (l<=lx && rx<=r) { //seg full
                tree[x]=op(tree[x],v);
            } else {
                int m = (lx+rx)/2;
                update(l,r,v,2*x,lx,m);
                update(l,r,v,2*x+1,m+1,rx); 
            }
        }
        ll query(int i) {return query(i,1,1,sz);}
        ll query(int i, int x, int lx, int rx){
            push_down(x,lx,rx);
            if (lx==rx) return tree[x];
            int m = (lx+rx)/2;
            ll res;
            if (i<=m) res = query(i,2*x,lx,m);
            else res = query(i,2*x+1,m+1,rx);
            return op(res,tree[x]);
        }
};
void __print(SegTree x) {vector<string> v; for (int i=1;i<=x.sz;i++) v.push_back(x.query(i)==x.NO_OP?"x":to_string(x.query(i))); __print(v);}


int main() {
    int N,M; cin >> N >> M;
    SegTree segtree = SegTree(N);
    for (int i=0;i<M;i++){
        int type; cin >> type;
        if (type == 1){
            int l, r, v; cin >> l >> r >> v;
            l++;
            segtree.update(l,r,v);
            dbg(segtree);
        }
        else {
            int x; cin >> x;
            x++;
            cout << segtree.query(x) << endl;
        }
    }
    

    return 0;
}