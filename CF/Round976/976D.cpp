#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';
const ll inf = 2e18;

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
#define dbgM(x) cout << "\e[34m" << "CASE: " << x << "\e[34m" << endl;
#else
#define dbg(x...)
#define dbgM(x) 
#endif

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

int D = 10;









void solve(){
    int N, M; cin >> N >> M;
    vector<vector<vector<int>>> presum(D+1,vector<vector<int>>(D+1, vector<int>(2*N+2)));
    for (int q=0;q<M;q++){
        int a, d, k; cin >> a >> d >> k;
        if (k > 0){
            presum[d][a%d][a] += 1;
            presum[d][a%d][a+k*d+k] -= 1;
        }
    }

    DSU dsu(N);
    for (int d=1;d<=D;d++){
        for (int modd=0;modd<d;modd++){
            int net = 0;
            for (int a=modd;a<=N;a+=d){
                if (net>0 && net+presum[d][modd][a]>0) dsu.join(a, a-d);
                net += presum[d][modd][a];
            }
        }
    }

    set<int> res;
    for (int i=1;i<=N;i++){
        res.insert(dsu.getPar(i));
    }
    cout << res.size() << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}