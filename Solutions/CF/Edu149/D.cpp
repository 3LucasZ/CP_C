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

void solve(){
    int N; cin >> N;
    vector<char> A(N);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }
    dbg(N,A);

    //conditions like stats :)
    int z=0;
    for (int i=0;i<N;i++){
        if (A[i]=='(') z++;
        else z--;
    }
    if (z!=0){
        cout << -1 << nl;
        return;
    }

    //ez case: works fw or bw so 1

    z=0;
    bool t1 = true;
    for (int i=0;i<N;i++){
        if (A[i]=='(') z++;
        else {
            z--;
            if (z<0) t1=false;
        }
    }

    z=0;
    bool t2 = true;
    for (int i=N-1;i>=0;i--){
        if (A[i]=='(') z++;
        else {
            z--;
            if (z<0) t2=false;
        }
    }

    if (t1||t2){
        cout << 1 << nl;
        for (int i=0;i<N;i++) cout << 1 << " ";
        cout << nl;
        return;
    }

    //greedy: take while you can, assign those 1, rest are 2
    int net = 0;
    int openCnt = 0;
    vi ret(N, 1);

    for (int i=0;i<N;i++){
        if (A[i]=='(') {
            if (openCnt==N/2){
                ret[i]=2;
            }
            else {
                net++;
                openCnt++;
            }
        }
        else {
            if (net==0){
                ret[i]=2;
                openCnt++;
            } else {
                net--;
            }
        }
    }
    cout << 2 << nl;
    for (int i=0;i<N;i++){
        cout << ret[i] << " ";
    }
    cout << nl;
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