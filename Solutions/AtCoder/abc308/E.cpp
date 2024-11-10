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
const bool multi = false;










int N;
vector<int> A;
vector<char> S;

ll fix(int m, int e, int x){
    dbg(m,e,x);
    int mex = 0;
    unordered_set<int> set;
    set.insert(m);
    set.insert(e);
    set.insert(x);
    if (!set.count(0)) mex=0;
    else if (!set.count(1)) mex=1;
    else if (!set.count(2)) mex=2;
    else if (!set.count(3)) mex=3;
    dbg(mex);

    vector<int> ok('Z');
    ok['M']=m;
    ok['E']=e;
    ok['X']=x;
    dbg(ok);

    vector<char> S2;
    for (int i=0;i<N;i++){
        if (A[i]==ok[S[i]]){
            S2.push_back(S[i]);
        }
    }
    int M = sz(S2);
    dbg(M,S2);

    vector<ll> preM(M);
    for (int i=0;i<M;i++){
        if (i>0) preM[i]=preM[i-1];
        if (S2[i]=='M') preM[i]++;
    }
    vector<ll> sufX(M);
    for (int i=M-1;i>=0;i--){
        if (i<M-1) sufX[i]=sufX[i+1];
        if (S2[i]=='X') sufX[i]++;
    }

    ll ret = 0;
    for (int i=1;i<=M-2;i++){
        if (S2[i]=='E') ret+=preM[i-1]*sufX[i+1]*mex;
    }
    dbg(ret);
    return ret;
}
void solve(){
    cin >> N;
    A = vector<int>(N);
    S = vector<char>(N);
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> S[i];
    dbg(N,A,S);

    ll ans = 0;
    for (int m=0;m<=2;m++){
        for (int e=0;e<=2;e++){
            for (int x=0;x<=2;x++){
                ans+=fix(m,e,x);
            }
        }
    }

    cout << ans << nl;
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