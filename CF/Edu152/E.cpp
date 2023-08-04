//FAIL (keep for archive)
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
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const bool multi = false;









class SegTree {
    ll op(ll a, ll b){
        return a+b;
    }
    public:
        int sz;
        vector<ll> tree;
        
        SegTree (int n){
            init(n);
        }
        SegTree(int n, vector<ll> arr){
            init(n);
            for (int i=1;i<=n;i++) tree[i+sz-1]=arr[i];
            for (int i=sz-1;i>=1;i--)tree[i]=op(tree[i*2],tree[i*2+1]);
        }
        void init(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree = vector<ll>(2*sz+1);
        }
        void update(int k, ll v){
            k++;
            k+=sz-1;
            tree[k]=op(tree[k],v);
            for (k/=2;k>=1;k/=2) tree[k]=op(tree[2*k],tree[2*k+1]);
        }
        ll get(int x) {return tree[x+1+sz-1];}
        ll query(int a, int b) {
            a++; b++;
            a+=sz-1; b+=sz-1;
            ll ret = 0;
            while (a<=b){
                if (a%2==1) ret=op(ret,tree[a++]);
                if (b%2==0) ret=op(ret,tree[b--]);
                a/=2; b/=2;
            }
            return ret;
        }
};
void __print(SegTree x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.query(i,i)); __print(v);}



template<typename T>
vector<int> nxt(vector<T> v, function<bool (T, T)> cmp, bool left=true){
    stack<T> s; vector<int> ret(sz(v));
    if (left) for (int i=0;i<sz(v);i++){ //1a
            while (!s.empty() && cmp(v[i],v[s.top()]))s.pop();
            if (!s.empty()) ret[i]=s.top();
            else ret[i]=-1; //2a
            s.push(i);
        }
    else for (int i=sz(v)-1;i>=0;i--){ //1b
            while (!s.empty() && cmp(v[i],v[s.top()]))s.pop();
            if (!s.empty()) ret[i]=s.top();
            else ret[i]=sz(v); //2b
            s.push(i);
        }
    return ret;
}



void solve(){
    int n; cin >> n;
    vector<int> A(n); for (int i=0;i<n;i++) cin >> A[i];
    dbg(n,A);

    vector<int> lless = nxt<int>(A,less<int>()); dbg(lless);
    vector<int> rless = nxt<int>(A,less<int>(),false); dbg(rless);
    vector<int> lgreat = nxt<int>(A,greater<int>()); dbg(lgreat);
    vector<int> rgreat = nxt<int>(A,greater<int>(),false); dbg(rgreat);

    ll ans = 0;
    SegTree seg(n);
    for (int i=0;i<n;i++){
        ans += seg.query(lgreat[i]+1,i-1)*(rgreat[i]-i);
        seg.update(i,i-lless[i]);
        dbg(seg);
    }
    cout << ans << nl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}