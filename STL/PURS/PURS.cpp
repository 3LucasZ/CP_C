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
const bool multi = true;













class PURS {
    public:
        int size;
        vector<ll> tree;
        vector<ll> val;
        PURS (int n){
            init(n);
        }
        PURS(int n, vector<int> arr){
            init(n);
            for (int i=1;i<=n;i++){
                tree[i+size-1]=arr[i];
                val[i]=arr[i];
            }
            for (int i=size-1;i>=1;i--)tree[i]=tree[i*2]+tree[i*2+1];
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
int main() {
    PURS()
    return 0;
}