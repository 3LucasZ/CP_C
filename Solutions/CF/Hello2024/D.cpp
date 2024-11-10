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
#define dbgM(x) cout << "\e[34m" << "CASE: " << x << "\e[34m" << endl ;
#else
#define dbg(x...)
#define dbgM(x) 
#endif

const bool multi = true;









int n;
vector<int> l;
vector<int> r;
vector<int> vis;
vector<int> a;

bool ok(int i){
    return i>0 && i<n+1 && (a[l[i]] == a[i] - 1 || a[r[i]] == a[i] - 1);
}

void solve(){
    cin >> n;
    l.clear(); l.resize(n+2);
    r.clear(); r.resize(n+2);
    vis.clear(); vis.resize(n+2);
    a.clear(); a.resize(n+2);
    dbg(n);

    for (int i=1;i<=n;i++){
        cin >> a[i];
        l[i] = i-1;
        r[i] = i+1;
        vis[i] = 0;
    }
    a[0]=a[n+1]=-5;
    dbg(a);

    priority_queue<pair<int,int>> pq; //value, index
    for (int i=1;i<=n;i++){
        if (ok(i)){
            vis[i] = 1; //in q for deletion
            pq.push({a[i],i});
        }
    }

    while (!pq.empty()) {
        dbg(pq.top());
        int x = pq.top().second; pq.pop();
        r[l[x]] = r[x];
        l[r[x]] = l[x];
        if (ok(l[x]) && !vis[l[x]]){
            vis[l[x]]=1;
            pq.push({a[l[x]],l[x]});
        } 
        if (ok(r[x]) && !vis[r[x]]) {
            vis[r[x]]=1;
            pq.push({a[r[x]],r[x]});
        }
    }
    dbg(vis);

    int left = 0;
    int lastLeft = 0;
    for (int i=1;i<=n;i++) if (vis[i]==0) {
        left++;
        lastLeft = i;
    }
    if (left == 1 && a[lastLeft] == 0) cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}