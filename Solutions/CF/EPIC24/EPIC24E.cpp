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








int n;
vector<vector<int>> t;
vector<ll> a;
ll sol;


vector<ll> solve_tree(int par, int node){
    //multipliers dict
    vector<ll> mults(n+2);
    ll childsum = 0;
    //case: leaf
    if (sz(t[node])==1 and par != 0){
        mults[0] = 1e14;
        return mults;
    }
    //solve per child
    for (int child : t[node]){
        if (child == par) continue;
        //update mults w/ child
        vector<ll> child_mult = solve_tree(node, child);
        for (int i=0;i<=n;i++) {
            mults[i+1] += child_mult[i];
        }
        childsum += a[child];
    }
    //case: already solved
    if (a[node] <= childsum){
        mults[0] += childsum - a[node];
        return mults;
    }
    //case: needs solve
    //greed mults
    int i=1;
    while (a[node] > childsum + mults[i]){
        sol += i*mults[i];
        childsum += mults[i];
        mults[i]=0;
        i++;
    }
    ll amt = a[node] - childsum;
    sol += i*amt;
    childsum += amt;
    mults[i] -= amt;    
    return mults;
}


void solve(){
    cin >> n;
    a.clear(); a.resize(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    t.clear(); t.resize(n+1);
    for (int u=2;u<=n;u++){
        int v;
        cin >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dbg(n,a,t);

    sol = 0;
    solve_tree(0, 1);
    cout << sol << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}