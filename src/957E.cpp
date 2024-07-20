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
#define dbgM(x) cout << "\e[34m" << "CASE: " << x << "\e[34m" << endl;
#else
#define dbg(x...)
#define dbgM(x) 
#endif

const bool multi = true;













void solve(){
    ll n;
    cin>>n;
    ll cur=n;
    vector<ll> dig;
    while(cur>0){
        dig.push_back(cur%10);
        cur/=10;
    }
    reverse(all(dig));

    ll tar = 0;
    vector<pair<ll,ll>> ret;
    for (ll l=0;l<=7;l++){
        for (ll a=1;a<=10000LL;a++){
            ll b=sz(dig)*a-l;
            if (b<1 || b>=a*n){
                continue;
            }
            if(tar==n*a-b){
                ret.push_back({a,b});
            }
        }
        tar = 10*tar + dig[l%sz(dig)];
    }
    cout<<sz(ret)<<nl;
    for (auto p:ret){
        cout<<p.first<<" "<<p.second<<nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}