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

const bool multi = true;













void solve(){
    int N; cin >> N;
    vector<int> ans(N); //you will rcv pair <+/-i, index> -> ans[index] = +/-i
    vector<pair<int,int>> B(N); //given <value,index>
    for (int i=0;i<N;i++) {
        int x; cin >> x;
        B[i]=pair(x,i);
    }
    sort(all(B));
    dbg(N);
    dbg(B);

    int pos = 0; int posptr = N-1;
    int neg = 0; int negptr = 0;
    bool posFirst = (B[N-1].first == N);
    bool negFirst = (B[0].first == 0);
    if (posFirst ^ negFirst == 0) {
        cout << "NO" << nl; return;
    }

    int turn = posFirst?1:-1;

    for (int i=N-1;i>=0;i--){
        dbg(i,turn);
        if (turn==1){
            pos++;
            if (B[posptr].first!=N-neg) {
                cout << "NO" << nl; return;
            }
            ans[B[posptr].second]=i+1;
            if (posptr>0 && B[posptr-1].first!=B[posptr].first) turn*=-1;
             posptr--;
        } else {
            neg++; 
            if (B[negptr].first!=pos) {
                cout << "NO" << nl; return;
            }
            ans[B[negptr].second]=-(i+1);
            if (negptr<N-1 && B[negptr+1].first!=B[negptr].first) turn*=-1;
            negptr++;
        }
    }
    dbg(ans);
    cout << "YES" << nl;
    for (int i=0;i<N;i++){
        cout << ans[i] << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}