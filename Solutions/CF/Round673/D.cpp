#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
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

const bool multi = true;








int N;
vector<int> A;
vector<array<int,3>> ans;

void go(int x, int y, int z) {
    A[x]-=x*z;
    A[y]+=x*z;
    ans.push_back({x,y,z});
}

void solve(){
    //in
    cin >> N;
    A.clear();A.resize(N+1);
    ans.clear();
    for (int i=1;i<=N;i++) cin >> A[i];
    dbg(N,A);

    //force
    int sum = 0; for (int i=1;i<=N;i++) sum+=A[i];
    if (sum%N) {
        cout << -1 << nl; 
        return;
    }
    
    //push all to 1
    for (int i=2;i<=N;i++){
        //make A[i] divisible by i
        if (A[i]%i){
            go(1,i,i-A[i]%i);
        }
        //push A[i] to 1
        go(i,1,A[i]/i);
    }
    //smooth to goal
    for (int i=2;i<=N;i++){
        go(1,i,sum/N);
    }

    //ret
    cout << sz(ans) << nl;
    for (auto &[x,y,z] : ans){
        cout << x << " " << y << " " << z << nl;
    }

    assert(sz(ans)<=3*N);
    for (int i=1;i<=N;i++) assert(A[i]==sum/N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}