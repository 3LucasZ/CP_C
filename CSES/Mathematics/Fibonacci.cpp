#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<ll>> mat;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()


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






mat identity = {{1,0},{0,1}};
ll MOD=1e9+7;
mat mul(mat a, mat b){
    assert(sz(b)==sz(a[0])); //Rule: a cols == b rows
	mat ret(sz(a),vector<ll>(sz(b[0]))); //Ret: a rows x b cols
    for (int i=0;i<sz(a);i++){
        for (int j=0;j<sz(b[0]);j++){
            for (int k=0;k<sz(b);k++){
                ret[i][j] = (ret[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return ret;
}
mat po(mat a, ll b){
    if (b==0) return identity;
    else if (b%2==0) return po(mul(a,a), b/2);
    else return mul(a,po(a,b-1));
}




int main() {
    ll N; cin >> N;

    mat init = {{1,0}};
    mat op = {{1, 1}, {1, 0}};
    mat tran = po(op,N);
    mat res = mul(init,tran);
    dbg(res);

    cout << res[0][1] << endl;

    return 0;
}