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

const bool multi = true;













void solve(){
    int n, m; cin >> n >> m;
    vector<char> s(n+2); for (int i=1;i<=n;i++) cin >> s[i];
    dbg(n,m,s);

    //dp
    vector<int> L(n+2); L[0]=0;
    for (int i=1;i<=n;i++){
        if (s[i]=='0') L[i]=i;
        else L[i]=L[i-1];
    }
    dbg(L);
    vector<int> R(n+2); R[n+1]=n+1;
    for (int i=n;i>=1;i--){
        if (s[i]=='1') R[i]=i;
        else R[i]=R[i+1];
    }
    dbg(R);
    
    //qry 
    unordered_set<ll> mp;
    for (int i=0;i<m;i++){
        int l, r; cin >> l >> r;
        dbg(i);
        dbg(l,r);
        l = R[l];
        r = L[r];
        dbg(l,r);
        if (l>r) mp.insert(0);
        else mp.insert(l*1000000LL+r);
    }

    //ret
    cout << sz(mp) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}