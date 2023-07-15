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

const bool multi = false;











class RUPS {
    public:
        int sz;
        vector<ll> tree;
        RUPS(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree.resize(2*sz+1);
        }
        ll get(int k){
            long ret = 0;
            for (k+=sz-1;k>=1;k/=2) ret+=tree[k];
            return ret;
        }
        void add(int a, int b, int x) {
            a+=sz-1;
            b+=sz-1;
            while (a<=b){
                if (a%2==1) tree[a++]+=x;
                if (b%2==0) tree[b--]+=x;
                a/=2;
                b/=2;
            }
        }
};
void __print(RUPS x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.get(i)); __print(v);}


void solve(){
    int N, K; 
    cin >> N >> K;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    dbg(N,K,A);

    RUPS rups(N);
    ll ans = 0;
    vector<vector<int>> numSeg(N+1);
    for (int i=0;i<N;i++){
        numSeg[A[i]].push_back(i);
        int sz = sz(numSeg[A[i]]);
        if (sz==1) continue;
        int l = numSeg[A[i]][sz-2];
        int r = numSeg[A[i]][sz-1];
        ans += r-l ;
        rups.add(l+1,r,r-l);
    }
    dbg("init",ans);
    dbg(numSeg);
    dbg(rups);

    priority_queue<ll> points;
    for (int i=1;i<=N;i++){
        points.push(rups.get(i));
    }
    
    for (int i=1;i<=K-1;i++){
        ans-=points.top();
        points.pop();
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}