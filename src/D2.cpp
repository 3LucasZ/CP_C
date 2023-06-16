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
const bool multi = true;

void solve(){
    int N; cin >> N;
    vi A(N); for (int i=0;i<N;i++) cin >> A[i];
    dbg(N,A);

    ll ret = 0;
    for (int i=0;i<N;i++){
        ret+=(ll)i*(N-i);
    }

    vector<pair<int,int>> events(N);
    for (int i=0;i<N;i++){
        events[i].f = A[i];
        events[i].s = i;
    }

    vi x(N);
    vi k(N);
    vi y(N);

    sort(all(events));
    dbg(events);
    set<int> past;
    for (int ti=0;ti<N;ti++){
        int i = events[ti].s;
        dbg(i,past);

        if (past.ub(i)!=end(past)) k[i]=*past.ub(i);
        if (past.lb(i)!=end(past)) y[i]=*past.lb(i);
        past.insert(i);
    }

    sort(all(events),less<pair<int,int>>());
    set<int> future;
    for (int ti=0;ti<N;ti++){
        int i = events[ti].s;
        if (future.ub(k[i])!=end(future)) x[i]=*future.ub(k[i]);
        future.insert(i);
    }

    dbg(x);
    dbg(k);
    dbg(y);
    for (int i=0;i<N;i++) {
        ret-=(k[i]-x[i])*(y[i]-i);
    }
     
    cout << ret << nl;
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