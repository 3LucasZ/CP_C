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













void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    dbg(n,a);

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -10*n)));
    dp[0][0][0]=0;
    for (int i=0;i<=n-1;i++){
        for (int active=0;active<=n-1;active++){
            for (int delay=0;delay<=n-2;delay++){
                // dbg(i,active,delay);
                if (i+1-a[i+1] <= delay and i+1-a[i+1] >=0){
                    ckmax(dp[i+1][active+1][delay],dp[i][active][delay]+1);
                }
                if (active > 0){
                    ckmax(dp[i+1][active-1][delay+2],dp[i][active][delay]);
                }
                if (active == 0){
                    ckmax(dp[i+1][active][delay],dp[i][active][delay]);
                }
            }
        }
    }
    int ret = 0;
    for (int delay=0;delay<=n;delay++){
        ckmax(ret, dp[n][0][delay]);
    }
    cout << ret << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}