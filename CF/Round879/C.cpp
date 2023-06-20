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
    vector<char> S(N);
    vector<char> T(N);
    for (int i=0;i<N;i++) cin >> S[i];
    for (int i=0;i<N;i++) cin >> T[i];
    dbg(S,T);
    int ans = 1000* N;

    //Case 1
    int dif1 = 0;
    for (int i=0;i<N;i++){
        if (S[i]!=T[i]) dif1++;
    }
    ans=min(ans,2*dif1+(dif1%2==1?-1:0));
    if (dif1==0 || dif1==1) {
        cout << dif1 << nl;
        return;
    }
    dbg(dif1);

    //Case 2
    int dif2 = 0;
    reverse(all(S));
    for (int i=0;i<N;i++){
        if (S[i]!=T[i]) dif2++;
    }
    if (dif2==0){
        cout << 2 << nl;
        return;
    }
    ans=min(ans,2*dif2+(dif2%2==0?-1:0));
    dbg(dif2);
    

    //Case 3
    bool palyS = true;
    for (int i=0;i<N;i++){
        if (S[i]!=S[N-1-i]) palyS=false;
    }
    bool palyT = true;
    for (int i=0;i<N;i++){
        if (T[i]!=T[N-1-i]) palyT=false;
    }
    bool paly = palyS || palyT;
    dbg(paly);
    if (paly){
        ans=min(ans,min(2*dif1,2*dif2)-1);
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