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

const bool multi = true;










//0 indexed
class BOOL_SAT {
    public:
        int sz;
        vector<vector<pair<int,int>>> graph; //constraints graph
        BOOL_SAT(int n){
            this->sz = n;
            graph = vector<vector<pair<int,int>>>(sz);
        }
        void add_constraint(int u, int v, bool same){
            graph[u].push_back(pair(v,same?1:-1));
            graph[v].push_back(pair(u,same?1:-1));
        }
        vector<int> val;
        bool res;
        bool solve(){
            val = vector<int>(sz,0);
            res = true;
            for (int i=0;i<sz;i++) if (!val[i]) {
                val[i]=1;
                DFS(i);
            }
            return res;
        }
        void DFS(int node){
            for (auto child : graph[node]){
                if (val[child.first]){
                    res = res && (val[child.first]==val[node]*child.second);
                } else {
                    val[child.first]=val[node]*child.second;
                    DFS(child.first);
                }
            }
        }
};


void solve(){
    int R, C, K; cin >> R >> C >> K;
    dbg(R,C,K);
    vector<vector<pair<int,char>>> rEvents(R+1);
    vector<vector<pair<int,char>>> cEvents(C+1);
    for (int i=0;i<K;i++){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        char type;
        if (c2 > c1) type='r';
        else type = 'l';
        int rx = min(r1,r2); int cx = min(c1,c2);
        rEvents[rx].push_back(pair(cx,type));
        cEvents[cx].push_back(pair(rx,type));
    }
    dbg(rEvents);

    BOOL_SAT cSAT(C+1);
    for (int r=1;r<=R;r++){
        for (int i=1;i<sz(rEvents[r]);i++){
            cSAT.add_constraint(rEvents[r][i-1].first,rEvents[r][i].first,rEvents[r][i-1].second==rEvents[r][i].second);
        }
    }

    BOOL_SAT rSAT(R+1);
    for (int c=1;c<=C;c++){
        for (int i=1;i<sz(cEvents[c]);i++){
            rSAT.add_constraint(cEvents[c][i-1].first,cEvents[c][i].first,cEvents[c][i-1].second==cEvents[c][i].second);
        }
    }
    
    bool res = rSAT.solve() && cSAT.solve();
    cout << (res?"YES":"NO") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}