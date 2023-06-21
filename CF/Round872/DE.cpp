#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
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
const bool multi = false;

ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

const int MAXF = 2e5;
ll fact[MAXF+1];
ll invfact[MAXF+1];
void setupChs() {
    fact[0]=1; for (int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=po(fact[MAXF],MOD-2);
    for (int i=MAXF;i>=1;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll chs(int n, int k) {
    //dbg(n,k);
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int N,K;
vector<vector<int>> graph;
vector<int> gsz;
ll ans;

int DFS(int node, int par){
    int sz = 1;
    for (int child : graph[node]){
        if (child==par) continue;
        sz += DFS(child,node);
    }
    gsz[node]=sz;
    ll pre = chs(sz,K/2)*chs(N-sz,K/2); 
    dbg(pre);

    ans = (ans + pre)%MOD;
    return sz;
}

void solve(){
    //input + reset DS + setup
    setupChs();
    cin >> N >> K;
    graph.resize(N+1);
    gsz.resize(N+1);
    ans = 0;
    dbg(N,K);
    for (int i=0;i<N-1;i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dbg(graph);
    if (K%2==1) {
        cout << 1 << nl;
        return; 
    }

    //cntrb sum
    DFS(1,0);

    //ret
    dbg(ans);
    dbg(gsz);
    cout << 1+ ans * po(chs(N,K),MOD-2) % MOD;
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