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

class PURS {
    public:
        int sz;
        vector<ll> tree;
        PURS(int n){
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
void __print(PURS x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.get(i)); __print(v);}

void solve(){
    int N; cin >> N;
    vector<int> A(N); for (int i=0;i<N;i++) cin >> A[i];

    vector<PURS> ans;
    for (int z=0;z<2;z++) {
    ans.push_back(PURS(2*N));
    for (int i=1;i<=N;i++){
        int L = N+A[i-1]-i+1;
        int R = 2*N-i;
        if (R-L+1>N) R-=N;
        ans[z].add(L,R,1);
        dbg(A[i-1],L,R);
    }
    reverse(all(A));
    }
    dbg(N,A);

    int Q; cin >> Q;
    int shift = 0;
    int r = 1;

    cout << ans[0].get(shift) + ans[0].get(shift+N) << nl;
    for (int i=0;i<Q;i++){
        int t; cin >> t; 
        if (t==1){
            int x; cin >> x;
            shift-=r*x;
        } else if (t==2){
            int x; cin >> x;
            shift+=r*x;
        }
        if (t==3) r = -1*r;
        
        shift=(shift+N)%N;
        if (shift==0) shift = N;
        int shift2 = (-shift+N)%N;
        if (shift2==0) shift2 = 0;

        if (r==1){
            cout << ans[0].get(shift) + ans[0].get(shift+N);
        } else {
            cout << ans[1].get(shift2) + ans[1].get(shift2+N);
        }
        cout << nl;
    }

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