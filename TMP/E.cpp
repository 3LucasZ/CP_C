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
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const bool multi = false;











vector<bool> isPrime;
vector<ll> primes;
ll MOD;
vector<ll> primeFactorize(ll val){
    vector<ll> ret;
    for (int pi=0;primes[pi]*primes[pi]<=val;pi++){
        ll p = primes[pi];
        while (val%p==0){
            ret.push_back(p);
            val/=p;
        }
    }
    if (val>1) ret.push_back(val);
    return ret;
}
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

void solve(){
    ll x, q; cin >> x >> q >> MOD; dbg(x,q,MOD);
    unordered_map<ll,int> pCnt;
    vector<ll> init = primeFactorize(x);
    ll ans = 1;
    ll weird = 0;
    for (ll p : init) {
        if (p==2) continue;
        pCnt[p]++;
        if ((pCnt[p]+1)%MOD==0){
            weird++;
        } else {
            ans = ans*(pCnt[p]+1)%MOD;
        }
        if ((pCnt[p])%MOD==0){
            weird--;
        } else {
            ans = ans*po(pCnt[p],MOD-2)%MOD;
        }
    }
    dbg(ans);
    for (int i=0;i<q;i++){
        cin >> x; dbg(x);
        init = primeFactorize(x); dbg(init);
        for (ll p : init) {
            if (p==2) continue;
        pCnt[p]++;
        if ((pCnt[p]+1)%MOD==0){
            weird++;
        } else {
            ans = ans*(pCnt[p]+1)%MOD;
        }
        if ((pCnt[p])%MOD==0){
            weird--;
        } else {
            ans = ans*po(pCnt[p],MOD-2)%MOD;
        }
        }
        if (weird!=0) cout << 0 << nl;
        else cout << ans << nl;
    }
}


void sieveLEQ(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;


    sieveLEQ(1e5);


    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}