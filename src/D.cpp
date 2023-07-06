#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int)(x).size()
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

class PURS {
    public:
        int sz;
        vector<ll> tree;
        vector<ll> val;
        PURS (int n){
            init(n);
        }
        void init(int n){
            sz = 1;
            while (sz < n) sz *= 2;
            tree = vector<ll>(2*sz+1);
            val = vector<ll>(n+1);
        }
        void add (int k, int x){
            set(k,tree[k+sz-1]+x);
        }
        void set(int k, long x){
            val[k]=x;
            k+=sz-1;
            tree[k]=x;
            for (k/=2;k>=1;k/=2) tree[k]=tree[2*k]+tree[2*k+1];
        }
        long sum(int a, int b) {
            a+=sz-1; b+=sz-1;
            long ret = 0;
            while (a<=b){
                if (a%2==1) ret+=tree[a++];
                if (b%2==0) ret+=tree[b--];
                a/=2;
                b/=2;
            }
            return ret;
        }
};
void __print(PURS x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.sum(i,i)); __print(v);}






void solve(){
    int N,M,Q; cin >> N >> M >> Q;
    dbg(N,M,Q);

    vector<int> S(N+1); 
    for (int i=1;i<=N;i++) {
        char x; cin >> x;
        S[i] = x-'0';
    }
    dbg(S);

    vector<vector<int>> events(N+1);
    for (int id=1;id<=M;id++){
        int L, R; cin >> L >> R;
        events[L].push_back(id);
        events[R].push_back(-id);
    }
    dbg(events);

    set<int> active;
    vector<int> minSeg(N+1);
    int matter = N;
    for (int t=1;t<=N;t++){
        //add segs
        for (int event : events[t]){
            if (event > 0) active.insert(event);
        }
        //set cost based on lowest active seg
        if (active.empty()) {
            minSeg[t]=INT_MAX;
            matter--;
        }
        else minSeg[t] = *active.begin();
        //remove segs
        for (int event : events[t]){
            if (event < 0) active.erase(-event);
        }
    }
    dbg(minSeg);
    
    vector<int> ord(N+1); for (int i=0;i<=N;i++) ord[i]=i;
    sort(all(ord), [&](int a, int b){
        return pair(minSeg[a],a) < pair(minSeg[b],b);
    });
    vector<int> cost(N+1); for (int i=0;i<=N;i++){
        cost[ord[i]]=i;
    }
    dbg(ord);
    dbg(cost);

    PURS purs = PURS(N);
    for (int i=1;i<=N;i++){
        purs.set(cost[i],S[i]);
    }
    dbg(purs);
    
    for (int i=0;i<Q;i++){
        int x; cin >> x;
        S[x]=1-S[x];
        purs.set(cost[x],S[x]);

        int ones = purs.sum(1,N);
        int swaps = ones-purs.sum(1,ones);
        cout << swaps << nl;
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