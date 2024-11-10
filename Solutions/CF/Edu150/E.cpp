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

struct seg {
    int l,r;
};
bool operator <(const seg &a, const seg &b){
	return a.l < b.l;
}
void __print(seg x) {cerr << "{" << x.l << ", " << x.r << "}";}

void solve(){
    //*in
    int N; cin >> N;
    vector<pair<int,int>> events(N);
    for (int i=0;i<N;i++){
        events[i].s = i+1;
        cin >> events[i].f;
    }
    ll M; cin >> M;
    sort(all(events),greater<pair<int,int>>());
    dbg(N, events);
    
    //*cnt
    vl cnt(N+1);
    map<seg,int> segs;
    segs[{1,N}]=N;

    for (int i=0;i<N;i++){
        pair<int,int> next = events[i];
        auto coverIt = segs.upper_bound({next.second,next.second});
        coverIt--;
        seg cover = coverIt->f;
        
        //cnt,er,ins
        cnt[cover.r-cover.l+1]+=(coverIt->s - next.first);
        segs.erase(cover);
        segs[{cover.l,next.s-1}]=next.first;
        segs[{next.s+1,cover.r}]=next.first;
    }
    dbg(cnt);

    //make M
    ll ans = M;
    for (int i=N;i>=1;i--){
        ll take = min(cnt[i],M/i);
        ll untake = cnt[i]-take;
        cnt[i-1]+=untake;
        M-=take*i;
        ans-=take;
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