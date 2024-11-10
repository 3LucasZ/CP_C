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
const int MAXN = 200000, LIM = 633;
int freq[LIM+1][MAXN+1]; 
vi A, B;

void solve(){
    //in
    cin >> N;
    A.resize(N);
    B.resize(N); 

    for (int i=0;i<N;i++) cin>>A[i];
    for (int i=0;i<N;i++) cin>>B[i];
    int lim = sqrt(2*N);
    
    for (int i=0;i<N;i++) if (A[i]<=lim) freq[A[i]][B[i]]++;
        
    //cnt ai = aj
    ll t1 = 0;
    for (int i=0;i<N;i++){
        if (A[i]<=lim){
            int srch = A[i]*A[i]-B[i];
            if (srch>=0 && srch <=N) t1+=freq[A[i]][srch];
        }
    }
    dbg(t1);
    
    //cnt ai and ai overcount
    for (int i=0;i<N;i++){
        if (A[i]<=lim){
            if (A[i]*A[i]==B[i]+B[i]) t1--;
        }
    }
    dbg(t1);

    t1/=2;

    //cnt ai > aj (wlog aj < lim)
    for (int i=0;i<N;i++){
        for (int j=1;j<A[i]&&A[i]*j<=2*N;j++){
            if (A[i]*j-B[i]>=0 && A[i]*j-B[i]<=N) t1+=freq[j][A[i]*j-B[i]];
        }
    }

    //clear freq
    for (int i=0;i<N;i++){
        if (A[i]<=lim) freq[A[i]][B[i]]--;
    }

    cout << t1 << nl;
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