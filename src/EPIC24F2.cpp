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

    //clusters
    vector<vector<bool>> cluster_group(n+1, vector<bool>(n+1));
    vector<vector<bool>> cluster(n+1, vector<bool>(n+1));
    for (int l=n-1;l>=1;l--){
        cluster[l][l+1]=l-a[l]>=0 and (l-a[l])%2==0;
        cluster_group[l][l-1]=true;
        for (int r=l+1;r<=n;r+=2){
            cluster[l][r] = cluster[l][r] or (l-a[l]>=0 and (l-a[l])%2==0 and cluster_group[l+1][r-1]);
            for (int k=l;k<=r-1;k+=2){
                bool ok = cluster_group[l][k-1] and cluster[k][r] and a[k]>=a[l-1]+1 and k-a[k]>=0 and (k-a[k])%2==0;
                cluster_group[l][r] = cluster_group[l][r] or ok;
            }
        }
    }
    //dbg
    // dbg("clusters");
    // for (int l=1;l<=n;l++){
    //     for (int r=1;r<=n;r++){
    //         if (cluster[l][r]){
    //             dbg(l,r);
    //         }
    //     }
    // }
    // dbg("cluster_groups");
    // for (int l=1;l<=n;l++){
    //     for (int r=1;r<=n;r++){
    //         if (cluster_group[l][r]){
    //             dbg(l,r);
    //         }
    //     }
    // }
    
    //dp
    vector<vector<bool>> dp(2*n+1, vector<bool>(2*n+1, false));
    dp[0][0] = true;
    for (int i=0;i<n;i++){
        for (int delay=0;delay<=n;delay++){
            //Case 1:
            dp[i+1][delay] = dp[i+1][delay] or dp[i][delay];
            //Case 2:
            for (int k=2;i+k<=n;k+=2){
                bool ok = dp[i][delay] and cluster[i+1][i+k] and i+1-a[i+1]<=delay and i+1-a[i+1]>=0;
                dp[i+k][delay+k] = dp[i+k][delay+k] or ok;
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
    cout << best/2 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}