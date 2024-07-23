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
    // dbg(n,a);

    //precomp
    vector<vector<vector<bool>>> ok(n+1, vector<vector<bool>>(n+1, vector<bool>(n+1, false)));
    for (int l=n;l>=1;l--){
        for (int r=l+1;r<=n;r+=2){
            for (int delay=0;delay<=n;delay++){
                //Case 1:
                for (int k=l+1;k<=r-1;k++){
                    ok[l][r][delay] = ok[l][r][delay] or (ok[l][k][delay] and ok[k+1][r][delay]);
                }
                //Case 2:
                ok[l][r][delay] = ok[l][r][delay] or ((l+1>=r-1 or ok[l+1][r-1][delay]) and (l-a[l]>=0 and l-a[l]<=delay and (l-a[l])%2==0));
                //Case 3:
                if (delay > 0){
                    ok[l][r][delay] = ok[l][r][delay] or ok[l][r][delay-1];
                }
            }
        }
    }
    //dbg
    // for (int l=1;l<=n;l++){
    //     for (int r=1;r<=n;r++){
    //         for (int delay=0;delay<=n;delay++){
    //             if (ok[l][r][delay]){
    //                 dbg(l,r,delay);
    //                 break;
    //             }
    //         }
    //     }
    // }
    // dbg('precomp');
    //dp
    vector<vector<bool>> dp(2*n+1, vector<bool>(2*n+1, false));
    dp[0][0] = true;
    for (int i=0;i<n;i++){
        for (int delay=0;delay<=n;delay++){
            //Case 1:
            dp[i+1][delay] = dp[i+1][delay] or dp[i][delay];
            //Case 2:
            for (int k=1;i+k<=n;k++){
                dp[i+k][delay+k/2] = dp[i+k][delay+k/2] or (dp[i][delay] and ok[i+1][i+k][delay]);
            }
        }
    }

    //ret
    int best = 0;
    for (int delay=0;delay<=n;delay++){
        if (dp[n][delay]){
            best = delay;
        }
    }
    cout << best << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}