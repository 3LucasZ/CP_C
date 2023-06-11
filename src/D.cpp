#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue> 
#include <set>

using namespace std;

typedef long long ll;
template<class T> using pq = priority_queue<T>;

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
template <class T> void swap(T& x, T& y) {T t=x; x=y; y=t;}

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
    vector<int> A(N); vector<int> B(N);
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> B[i];

    vector<multiset<int>> ms(N+1);
    for (int i=0;i<N;i++) {
        ms[A[i]].insert(B[i]);
    }
    
    ll ans = 0;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=2*N/i;j++){
            if (j>N) continue;
            int lhs = i*j;
            multiset<int> u = ms[i]; //less elements -> iter
            multiset<int> v = ms[j]; //more elements -> group
            if (sz(v) < sz(u)) swap(u,v);
            for (auto x : u){
                ans += v.count(lhs-x);
            }
        }
    }

    //overcounted some stuff lol
    for (int i=0;i<N;i++){
        if (A[i]*A[i]==B[i]+B[i]) ans--;
    }
    cout << ans/2 << nl;
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