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

void solve(){
    int N, M;
    cin >> N >> M;
    int leftT = 0;
    int rightT = 0;
    vi left(M+2);
    vector<bool> place(M+2);
    vi right(M+2);
    dbg(N,M);
    for (int i=0;i<N;i++){
        int x; cin >> x;
        if (x==-1) leftT++;
        else if (x==-2) rightT++;
        else {
            left[x]=1;
            right[x]=1;
            place[x]=true;
        }
    }

    //SAFETY CASE
    if (leftT+rightT == N){
        cout << max(M,max(leftT,rightT)) << nl;
        return;
    }
    //REGULAR CASE
    dbg(leftT,rightT);
    dbg(left);
    for (int i=1;i<=M;i++){
        left[i+1]+=left[i];
        left[i]=min(left[i]+leftT,i);
    }
    for (int i=M;i>=1;i--){
        right[i-1]+=right[i];
        right[i]=min(right[i]+rightT,M-i+1);
    }
    int ans = 0;
    for (int i=1;i<=M;i++){
        if (place[i] || i==0 || i==M+1) ans=max(ans,(i-1>=0?left[i-1]:0)+(i+1<=N?right[i+1]:0)+place[i]);
    }
    dbg(left);
    dbg(right);
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