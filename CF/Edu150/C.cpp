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

int N;
string str;

int sim(vi &s) {
    vector<bool> seen(5);
    int ret = 0;
    for (int i=N-1;i>=0;i--){
        ret+=pow(10,s[i]);
        for (int j=s[i]+1;j<5;j++){
            if (seen[j]) {
                ret-=2*pow(10,s[i]);
                break;
            }
        }
        if (!seen[s[i]])  seen[s[i]]=true;
    }
    return ret;
}

void solve(){
    cin >> str;
    N = sz(str);
    dbg(N,str);
    vi s(N);
    for (int i=0;i<N;i++) s[i]=str[i]-'A';
    dbg(s);

    int ans = -INT_MAX;

    vector<bool> seen(5);
    for (int i=N-1;i>=0;i--){
        if (!seen[s[i]]){
            seen[s[i]]=true;
            int tmp = s[i];
            for (int j=0;j<5;j++){
                s[i]=j;
                ans=max(ans,sim(s));
            }
            s[i]=tmp;
            dbg(i);
        }
    }

    for (int i=0;i<5;i++) seen[i]=false;
    dbg(sz(seen));
    for (int i=0;i<N;i++){
        if (!seen[s[i]]){
            seen[s[i]]=true;
            int tmp = s[i];
            for (int j=0;j<5;j++){
                s[i]=j;
                ans=max(ans,sim(s));
            }
            s[i]=tmp;
            dbg(i);
        }
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