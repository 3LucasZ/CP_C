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



ll MOD = 1e9+7;

//a ^ b
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

//a choose b
//M1: chs(N,K) = n!/[k!(n-k)!]
//M2: chs(N,K) = chs(N,K-1)*(N-K+1)/K
const int MAXF = 5000;
ll fact[MAXF+1];
ll invfact[MAXF+1];
void setupChs() {
    fact[0]=1; for (int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=po(fact[MAXF],MOD-2);
    for (int i=MAXF;i>=1;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll chs(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}









void solve(){
    int n; cin >> n;
    ll ans = 0;
    for (int s=0;s<=n;s++){
        for (int l=0;l<=s;l++){
            ll a = chs(min(n,2*s-l),s);
            ll b = chs(n-2*s+l-1,l);
            ll c = (2*s-l+1);
            if (l==0){
                ans = (ans + a*c%MOD)%MOD;
            } else {
                ans = (ans + a*b%MOD*c%MOD)%MOD;
            }
        }
    }
    cout << ans << nl;
}

int main() {
    setupChs();
    dbg(chs(0,0));
    dbg(chs(0,1));
    dbg(chs(1,0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}