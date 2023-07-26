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










vector<bool> isPrime;
vector<ll> primes;
void sieveLEQ(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}
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
int main() {
    sieveLEQ(1000);
    dbg(primes);
    dbg(primeFactorize(178));
    dbg(primeFactorize(6238945));
    return 0;
}