#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
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
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif




/*
TESTED AND VERIFIED:
https://cses.fi/problemset/task/1722/
NOTE:
Stored as you see it!
[1 0] 
[0 1]
==
|1 0|
|0 1|
HAZARD:
mult(a,b) means transform b by a. Very confusing, sometimes.
*/

typedef vector<vector<ll>> mat;
mat matFrom(int r, int c, ll fill=0) { return mat(r,vector<ll>(c, fill));};
mat matId(int n) { 
    mat ret = matFrom(n,n);
    for (int i=0;i<n;i++) ret[i][i]=1;
    return ret;
}

mat mul(const mat& a, const mat& b){
    //assert(sz(a[0])==sz(b)); //Rule: a cols == b rows
	mat ret(sz(a),vector<ll>(sz(b[0]))); //Ret: a rows x b cols
    //ret[r][c] = X(A[r],B[c]) where X is any operation like dot product
    for (int r=0;r<sz(a);r++) for (int c=0;c<sz(b[0]);c++){ //pick point r,c
        ret[r][c] = inf;
        for (int k=0;k<sz(b);k++){ //iter l->r
            ckmin(ret[r][c],a[r][k]+b[k][c]);
        }
    }
    return ret;
}

mat po(const mat& a, ll b){
    if (b==1) return a;
    else if (b%2==0) return po(mul(a,a), b/2);
    else return mul(a,po(a,b-1));
}

int main() {
    int N,M; ll K; cin >> N >> M >> K;
    mat graph = matFrom(N,N,inf);
    for (int i=0;i<M;i++){
        int u, v; ll c; cin >> u >> v >> c;
        ckmin(graph[u-1][v-1],c);
    }
    dbg(N,M,K);
    dbg(graph);

    mat ans = po(graph,K);
    dbg(ans);   

    if (ans[0][N-1]==inf) cout << -1 << endl;
    else cout << ans[0][N-1] << endl;
    return 0;
}