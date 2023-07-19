#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(unsigned int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x);
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '<'; __print(x.first); cerr << ", "; __print(x.second); cerr << '>';}
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









//range update: sum, range query: max
class SegTree {
    public:
        ll NEUTRAL = LLONG_MAX; //no fx on qry
        ll NO_OP = 0;  //label node as having no ops
        ll DEF_OP = 0; //default op on each node during init
        ll upd_op(ll a, ll b, ll k=1){ //plz ensure NO_OP has no fx on ops
            return a+b;
        }
        ll qry_op(ll a, ll b){ 
            return min(a,b);
        }
        void build(int x, int lx, int rx){ // build init val
            if (lx==rx) val[x]=0;
            else {
                int m = (lx+rx)/2;
                build(2*x,lx,m);
                build(2*x+1,m+1,rx);
                val[x]=qry_op(val[2*x],val[2*x+1]);
            }
        }
        //hidden------>
        int n;
        int sz;
        vector<ll> ops; //lazy ops on node combined value
        vector<ll> val; //qry val of subtree
        SegTree(int n){
            this->n = n;
            sz = 1; while (sz < n) sz *= 2;
            ops = vector<ll>(2*sz+1,DEF_OP);
            val = vector<ll>(2*sz+1,0);
            build(1,1,sz);
        }
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
                ops[x]=upd_op(ops[x],v);
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
void __print(SegTree x) {vector<string> v; for (int i=0;i<x.n;i++) v.push_back(x.query(i,i)==x.NO_OP?"x":to_string(x.query(i,i))); __print(v);}



void solve(){
    //grab
    int N, K; ll A; cin >> N >> K >> A;
    dbg(N,K,A);
    vector<vector<pair<int,int>>> linePoints(K+1);
    for (int i=0;i<N;i++){
        int x, y, c; cin >> x >> y >> c; y = K-y;
        linePoints[y].push_back(pair(x,c));
    }
    for (int i=0;i<=K;i++) sort(all(linePoints[i]));
    dbg(linePoints);

    //dp
    vector<int> arch(K+1);
    SegTree dp(K+1); dp.update(0,0,0);
    for (int i=1;i<=K;i++){
        //update dp[0]..dp[i-1]
        ll cost = 0;
        int last = 0;
        for (pair<int,int> point: linePoints[i]){
            dp.update(last,point.first-1,cost);
            cost += point.second;
            last = point.first;
        }
        dp.update(last,i-1,cost);
        if (i-2>=0) dp.update(0,i-2,A); //accum triangle grows by 1
        dbg(i,dp);
        //update dp[i]
        dp.update(i,i,min(i*A,dp.query(0,i-1)));
        arch[i]=dp.query(i,i);
        dbg(i,dp);
    }
    //ret
    dbg(arch);
    cout << arch[K] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}