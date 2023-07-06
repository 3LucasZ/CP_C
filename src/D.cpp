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
        int size;
        vector<ll> tree;
        vector<ll> val;
        PURS (int n){
            init(n);
        }
        void init(int n){
            size = 1;
            while (size < n) size *= 2;
            tree = vector<ll>(2*size+1);
            val = vector<ll>(n+1);
        }
        void add (int k, int x){
            set(k,tree[k+size-1]+x);
        }
        void set(int k, long x){
            val[k]=x;
            k+=size-1;
            tree[k]=x;
            for (k/=2;k>=1;k/=2) tree[k]=tree[2*k]+tree[2*k+1];
        }
        long sum(int a, int b) {
            a+=size-1; b+=size-1;
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




void solve(){
    int N,M,Q; cin >> N >> M >> Q;
    dbg(N,M,Q);

    vector<char> S(N+1); for (int i=1;i<=N;i++) cin >> S[i];
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
    for (int t=1;t<=N;t++){
        //add segs
        for (int event : events[t]){
            if (event > 0) active.insert(event);
        }
        //set cost based on lowest active seg
        minSeg[t] = *active.begin();
        //remove segs
        for (int event : events[t]){
            if (event < 0) active.erase(event);
        }
    }
    dbg(minSeg);
    
    vector<int> ord(N+1); for (int i=0;i<=N;i++) ord[i]=i;
    sort(all(ord), [&](int a, int b){
        return pair(minSeg[a],a) < pair(minSeg[b],b);
    });
    dbg(ord);

    PURS purs = PURS(N);
    for (int i=1;i<=N;i++){
        purs.set(ord[i],S[i]);
    }
    dbg(purs);
    
    // for (int i=0;i<Q;i++){
    //     int x; cin >> x;
    //     S[x]=1-S[x];
    //     int cost = getCost[x-1]+1;
    //     purs.set(cost,S[x]);
    // }
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