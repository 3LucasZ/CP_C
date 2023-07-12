#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#define dbgM(x) cerr << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const bool multi = true;







ll N;
vector<vector<int>> tree;
vector<ll> tsz;
vector<int> tpar;

void DFS(int node, int par){
    tpar[node]=par;
    for (int child : tree[node]){
        if (child==par) continue;
        DFS(child,node);
        tsz[node]+=tsz[child];
    }
    tsz[node]++;
}

void solve(){
    cin >> N;
    tree.clear(); tree.resize(N);
    for (int i=0;i<N-1;i++){
        int u, v; 
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dbg(N,tree);

    tsz.clear(); tsz.resize(N);
    tpar.clear(); tpar.resize(N);
    DFS(0,-1);
    dbg(tsz,tpar);

    vector<ll> P(N+2,0);
    vector<bool> vis(N,false); //infected node?

    //manual op for i=0
    vis[0]=true;
    P[0]=N*(N-1)/2;

    //auto op for i>0
    int L=0; int R=0;
    int Lc=0;
    for (int i=1;i<=N;i++){
        dbg(i,L,R);
        //0 tail
        if (L==0){
            for (int c : tree[0]) P[i]+=tsz[c]*(N-1-tsz[c]);
            P[i]/=2;
            P[i]+=N-1;
        }
        //1 tail
        else if (R==0){
            P[i]=tsz[L]*(N-tsz[Lc]);
        }
        //2 tail
        else {
            P[i]=tsz[L]*tsz[R];
        }
        //infect i and up
        if (i==N) break;
        int cur = i;
        while (!vis[cur]){
            if (L==0 && tpar[cur]==0) Lc = cur;
            vis[cur]=true;
            cur=tpar[cur];
        }
        //update L, R, check illegal
        if (cur==L) L=i;
        else if (cur==R) R=i;
        else break;
    }
    dbg(P);

    //calc
    for (int i=0;i<=N;i++){
        cout << P[i]-P[i+1];
        //if (i!=N) cout << " ";
        cout << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}