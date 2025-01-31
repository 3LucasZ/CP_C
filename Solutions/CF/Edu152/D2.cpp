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













void solve(){
    int n; cin >> n;
    vector<int> A(n+2); for (int i=1;i<=n;i++) cin >> A[i];
    dbg(n,A);

    vector<bool> vis(n+2);
    // for (int i=1;i<=n;i++){
    //     cout << vis[i] << " ";
    // }cout << nl;
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (A[i]==2 && !vis[i]){
            ans++;
            vis[i]=true;
            for (int j=i+1;j<=n&&!vis[j];j++){
                vis[j]=true;
                if (A[j]==0) break;
            }
            for (int j=i-1;j>=1&&!vis[j];j--){
                vis[j]=true;
                if (A[j]==0) break;
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << vis[i] << " ";
    // }cout << nl;

    int l; vis[0]=true; vis[n+1]=true;
    for (int i=1;i<=n;i++){
        if (!vis[i]&&vis[i-1])l=i;
        if (!vis[i]&&vis[i+1]){
            dbg(l,i);
            int zeros = 0;
            int oneGroups = 0;
            for (int j=l;j<=i;j++){
                if (A[j]==0) zeros++;
                if (A[j]==1 && (j==l || A[j-1]==0)) oneGroups++;
            }
            dbg(max(oneGroups,zeros));
            ans+=max(oneGroups,zeros);
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}