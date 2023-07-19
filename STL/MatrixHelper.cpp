#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


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




/*
TESTED AND VERIFIED:
https://cses.fi/problemset/task/1722/
NOTE:
Stored as you see it!
[1 0] 
[0 1]
==
|1 0|
|0 1|
HAZARD:
mult(a,b) means transform b by a. Very confusing, sometimes.
*/
typedef vector<vector<ll>> mat;
mat matFrom(int r, int c) { return mat(r,vector<ll>(c));};
mat matId(int n) { 
    mat ret = matFrom(n,n);
    for (int i=0;i<n;i++) ret[i][i]=1;
    return ret;
}

ll MOD=1e9+7;

mat mul(const mat& a, const mat& b){
    //assert(sz(a[0])==sz(b)); //Rule: a cols == b rows
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

mat po(const mat& a, ll b){
    if (b==0) return matId(sz(a));
    else if (b%2==0) return po(mul(a,a), b/2);
    else return mul(a,po(a,b-1));
}




int main() {
    mat m1 = {{6,-2},{3,7}};
    mat m2 = {{1,-2},{-3,4}};
    mat res = mul(m1,m2);
    dbg(res); //{{12,-20},{-18,22}}

    mat cur = {{1, 0}, {0, 1}};
    mat m = {{1, 1}, {1, 0}};
    mat fib = po(m,10);
    dbg(fib[0][1]); //55 is the 10th fibonacci

    mat m3 = {{1,2,3},{4,5,6},{7,8,9}};
    dbg(mul(m3,m3)); //{{30, 36, 42}, {66, 81, 96}, {102, 126, 150}}
    dbg(po(m3,2LL));


    return 0;
}