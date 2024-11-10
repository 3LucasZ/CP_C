#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int, int> pi;
//typedef pair<ll, ll> pll;

#define sz(x) (int)(x).size()
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
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
const bool multi = false;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};









const int MAXR = 500; 
const int MAXC = 500; 
char grid[MAXR][MAXC];
bool vis[MAXR][MAXC];
int R,C;
char nxt[1000];



void solve(){
    nxt['s']='n';
    nxt['n']='u';
    nxt['u']='k';
    nxt['k']='e';
    nxt['e']='s';

    cin >> R >> C;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> grid[i][j];
        }
    }
    dbg(R,C);
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cerr << grid[i][j] << " ";
        }
        cerr << nl;
    }
    cerr << nl;

    for (int i=0;i<R;i++) for (int j=0;j<C;j++) vis[i][j]=false;
    vis[0][0]=true;
    queue<pair<int,int>> q;
    q.push(pair(0,0));

    while (!q.empty()){
        pair<int,int> next = q.front();
        int r = next.first;
        int c = next.second;
        q.pop();

        for (int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if (nr<0 || nr>=R || nc < 0 || nc>=C || vis[nr][nc] || nxt[grid[r][c]]!=grid[nr][nc]) continue;
            q.push(pair(r+dr[i],c+dc[i]));
            vis[nr][nc]=true;
        }
    }

    if (vis[R-1][C-1]){
        cout << "Yes" << nl;
    } else {
        cout << "No" << nl;
    }
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