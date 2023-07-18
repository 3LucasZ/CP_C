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
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const bool multi = false;











ll graph[101][101];

void solve(){
    //in
    int N; int M; cin >> N >> M;
    for (int i=0;i<M;i++){
        int u, v; ll c; cin >> u >> v >> c;
        graph[u][v]=c;
        graph[v][u]=c;
    }
    dbg(graph[1][1]);
    for (int i=1;i<N;i++){
        dbg(graph[1][i]);
    }

    set<int> infected;
    infected.insert(N);
    ll time = 0;
    vector<pair<string,int>> games;
    while(infected.count(1)==0){
        dbg(infected);
        //find sus pairs, game time
        vector<pair<int,int>> sus;
        ll mn = LLONG_MAX;
        for (int u : infected){
            for (int v=1;v<=N;v++){
                if (graph[u][v]>0){
                    sus.push_back(pair(u,v));
                    mn = min(mn,graph[u][v]);
                }
            }
        }
        //emergency ret
        if (sz(sus)==0){
            cout << "inf" << nl;
            return;
        }
        //update time, games, infected
        time+=mn;
        string ans(N,'1'); for (int u : infected) ans[u-1]='0';
        games.push_back(pair(ans,mn));

        for (pair<int,int> edge : sus){
            graph[edge.first][edge.second]-=mn;
            graph[edge.second][edge.first]-=mn;
            if (graph[edge.first][edge.second]==0){
                infected.insert(edge.first);
                infected.insert(edge.second);
            }
        }
    }

    //ret
    cout << time << " " << sz(games) << nl;
    for (int i=0;i<sz(games);i++){
        cout << games[i].first << " " << games[i].second << nl;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}