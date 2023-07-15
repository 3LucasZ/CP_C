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

class SegTree {
    void op(ll &a, ll b){
        a = a+b;
    }
    public:
        int sz;
        vector<ll> tree;
        SegTree(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree.resize(2*sz+1);
        }
        ll query(int k){
            ll ret = 0;
            for (k+=sz-1;k>=1;k/=2) op(ret,tree[k]);
            return ret;
        }
        void update(int a, int b, int v) {
            a+=sz-1;
            b+=sz-1;
            while (a<=b){
                if (a%2==1) op(tree[a++],v);
                if (b%2==0) op(tree[b--],v);
                a/=2;
                b/=2;
            }
        }
};
void __print(SegTree x) {vector<ll> v; for (int i=1;i<=x.sz;i++) v.push_back(x.query(i)); __print(v);}


int main() {
    SegTree P = SegTree(8);
    P.update(1,5,3);
    P.update(5,8,2);
    dbg(P);

    return 0;
}