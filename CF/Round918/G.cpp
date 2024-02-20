#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

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






const ll INF = 2e13; //max cost between 2 points (max distance * max slowness)
const int inf = 2e8; //max distance between 2 points (max nodes * max edge)


void solve(){
    //in
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1,vector<int>());
    vector<vector<int>> dist(n+1, vector<int>(n+1, inf));
    for (int i=0;i<m;i++){
        int u, v, c; cin >> u >> v >> c;
        ckmin(dist[u][v],c);
        ckmin(dist[v][u],c);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> s(n+1); s[0]=inf;
    for (int i=1;i<=n;i++) cin >> s[i];
    dbg(s);

    //dist
    for (int i=1;i<=n;i++){
        vector<bool> vis(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,i});
        while (!pq.empty()){
            pair<int,int> next = pq.top(); pq.pop();
            if (vis[next.second]) continue;
            vis[next.second] = true;
            dist[i][next.second]=next.first;
            for (int j : graph[next.second]){
                if (!vis[j]){
                    pq.push({min(next.first+dist[next.second][j],inf),j});
                }
            }
        }
    }
    dbg(dist);

    //rank
    vector<int> r(n+1);
    for (int i=0;i<=n;i++) r[i] = i;
    sort(all(r),[s]( 
        const int lhs, const int rhs ){
            return s[lhs]>s[rhs];
            });
    dbg(r);

    //dp
    vector<ll> dp(n+1, INF);
    int src, sink = 0;
    for (int i=1;i<=n;i++){
        if (r[i]==1) src = i;
        if (r[i]==n) sink = i;
    }

    dp[src] = 0;
    for (int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ckmin(dp[i],dp[j]+s[r[j]]*dist[r[i]][r[j]]);
        }
    }
    
    ll ans = INF;
    for (int j=1;j<=n;j++){
       ckmin(ans,dp[j]+s[r[j]]*dist[r[j]][n]);
    }
    cout << ans << nl;
    dbg(dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}