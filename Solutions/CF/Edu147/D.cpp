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
const bool multi = true;

void solve(){
    //IN N,K,segs
    int N,K; cin >> N >> K;
    vector<pair<int,int>> segs(N);
    for (int i=0;i<N;i++){
        cin >> segs[i].first;
    }
    for (int i=0;i<N;i++){
        cin >> segs[i].second;
    }
    dbg(N,K);
    dbg(segs);

    //FIND R, Rseg, singles
    int R = 0;
    int Rseg = 0;
    int tot = 0;
    int single = 0;
    for (int i=0;i<N;i++){
        if (segs[i].first==segs[i].second) single++;
        tot+=segs[i].second-segs[i].first+1;
        R=segs[i].second;
        Rseg = i;
        if (tot >= K) break;
    }
    R-=tot-K;
    int cost = R+2*(Rseg+1);
    int ans = cost;

    //DNE CASE
    if (tot < K){
        cout << -1 << endl;
        return;
    }
    dbg(R,Rseg,tot,cost);
    dbg(single);

    //brute force picking keep min cost
    vector<int> force(2*N+2);
    force[0]=1;
    for (int i=0;i<N;i++){
        if (R <= segs[i].first && segs[i].first<=R+2*N){
            force[segs[i].first-R]=1;
        } 
        if (R <= segs[i].second && segs[i].second<=R+2*N){
            force[segs[i].second-R+1]=-1;
        }
    }

    dbg(force);
    for (int i=0;i<=2*N;i++) force[i+1]+=force[i];
    dbg(force);
    for (int i=1;i<=2*N;i++){
        cost++;
        if (force[i]==1 && force[i+1]==0 && force[i-1]==0) continue;
        if (force[i]==1 && force[i-1]==0 && single>0){
            cost+=2;
        }
        if (force[i]==1 && single > 0){
            single--;
            cost-=2;
        }
        ans=min(ans,cost);
    }

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