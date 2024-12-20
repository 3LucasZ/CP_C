#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';
const ll inf = 2e18;

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

/*
@daftdove 7/15/23
Verified: 
https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/B
https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C
Note:
0-indexed api
1-indexed implementation
Upd: associative
Qry: associative
Must: distributive property i.e. (a op v) cmb (b op v) === cmb(a,b) op v
Settings:
NEUTRAL, NO_OP, upd_op, qry_op, build(sets default val[]), DEF_OP(sets default op[])
Extensions:
(add, min)
NEUTRAL = inf, upd_op = a+b, qry_op = min(a,b)
(set, sum)
NEUTRAL = 0, upd_op = b*k, qry_op = a+b
*/

const ll MOD = 1e9+7;
class SegTree {
    public:
        const ll NEUTRAL = inf; //no fx on qry
        const ll DEF_VAL = 0; //default val on each node during init that has no build
        ll upd_op(ll a, ll b, ll k=1){ //plz ensure NO_OP has no fx on ops
            if (a==NO_OP) return b; if (b==NO_OP) return a; //keep
            return a+b;
        }
        ll qry_op(ll a, ll b){ 
            return min(a,b);
        }
        void build(int x, int lx, int rx, const vector<int> &v){ // build init val
            if (lx==rx) val[x]=lx-1<sz(v)?v[lx-1]:DEF_VAL;
            else {
                int m = (lx+rx)/2;
                build(2*x,lx,m,v);
                build(2*x+1,m+1,rx,v);
                val[x]=qry_op(val[2*x],val[2*x+1]);
                ops[x]=NO_OP;
            }
        }
        //hidden------>
        const ll NO_OP = inf+1;  //label node as having no ops
        int sz;
        vector<ll> ops; //lazy ops on node combined value
        vector<ll> val; //qry val of subtree
        SegTree(int n){
            sz = 1; while (sz < n) sz *= 2;
            ops = vector<ll>(2*sz+1,NO_OP);
            val = vector<ll>(2*sz+1,0);
        }
        void build(const vector<int> &v = vector<int>()){build(1,1,sz,v);}
        void push_down(int x, int lx, int rx) { //maintain invariant top(new) - bot(old)
            if (lx==rx) return;
            ops[2*x]=upd_op(ops[2*x],ops[x]);
            ops[2*x+1]=upd_op(ops[2*x+1],ops[x]);
            val[2*x]=upd_op(val[2*x],ops[x],(rx-lx+1)/2);
            val[2*x+1]=upd_op(val[2*x+1],ops[x],(rx-lx+1)/2);
            ops[x] = NO_OP;
        }
        void update (int l, int r, ll v){update(l+1,r+1,v,1,1,sz);}
        void update(int l, int r, ll v, int x, int lx, int rx) {
            push_down(x,lx,rx);
            if (lx>r || rx<l) return; //seg out
            else if (l<=lx && rx<=r) { //seg full
                ops[x]=upd_op(ops[x],v); //can be sus: (NO_OP+v)
                val[x]=upd_op(val[x],v,rx-lx+1);
            } else { //seg partial
                int m = (lx+rx)/2;
                update(l,r,v,2*x,lx,m); update(l,r,v,2*x+1,m+1,rx);
                val[x]=qry_op(val[2*x],val[2*x+1]);
            }
        }
        ll query(int l, int r) {return query(l+1,r+1,1,1,sz);}
        ll query(int l, int r, int x, int lx, int rx){
            push_down(x,lx,rx);
            if (lx>r || rx<l) return NEUTRAL; //seg out
            else if (l<=lx && rx<=r){
                return val[x]; //seg full
            } else { //seg partial
                int m = (lx+rx)/2;
                return qry_op(query(l,r,2*x,lx,m),query(l,r,2*x+1,m+1,rx));
            }
        }
};
void __print(SegTree x) {vector<string> v; for (int i=1;i<=x.sz;i++) v.push_back(x.query(i,i)==x.NO_OP?"x":to_string(x.query(i,i))); __print(v);}


int main() {
    int N,M; cin >> N >> M;
    SegTree segtree = SegTree(N);
    for (int i=0;i<M;i++){
        int type; cin >> type;
        if (type == 1){
            int l, r; cin >> l >> r; l++;
            ll v; cin >> v;
            dbg(l,r,v);
            segtree.update(l,r,v);
            dbg(segtree);
        }
        else {
            int l, r; cin >> l >> r; l++;
            dbg(l,r);
            cout << segtree.query(l,r) << nl;
        }
    }
    

    return 0;
}