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

int N;
void solve(){
    cin >> N;
    vector<pi> pairs(N+1);
    pairs[N] = pair{-1,-1};
    for (int i=0;i<N;i++){
        cin >> pairs[i].f >> pairs[i].s;
    }

    sort(all(pairs));
    dbg(pairs);

    int dp[N+1][N+1][2];

    //base
    for (int i=0;i<=N;i++) for (int j=0;j<=N;j++) for (int k=0;k<2;k++) dp[i][j][k]=10000;
    dp[1][0][0]=1;
    dp[1][1][1]=0;
    //trans
    for (int i=0;i<N;i++){
        for (int last=0;last<=N;last++){
            for (int q=0;q<2;q++){
                //skip i+1
                ckmin(dp[i+1][last][q],dp[i][last][q]+1);
                //take i+1 and half -> must intersect
                int tk = i+1; if (pairs[last].s > pairs[i+1].s) tk = last;
                if (q==1){
                    if (pairs[last].s >= pairs[i+1].f){
                        ckmin(dp[i+1][tk][0],dp[i][last][q]);
                    }
                }
                //take i+1 and open -> must NOT intersect
                else {
                    if (pairs[last].s < pairs[i+1].f){
                        ckmin(dp[i+1][i+1][1],dp[i][last][q]);
                    }
                }
            }
        }
    }
    //ret
    int ans = N;
    for (int i=0;i<=N;i++) ckmin(ans,dp[N][i][0]);
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