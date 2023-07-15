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













void solve(){
    int N; cin >> N;
    vector<int> A; 
    for (int i=0;i<N;i++){
        char x; cin >> x;
        A.push_back(x-'0');
    }

    int zeros = 0;
    for (int i=0;i<N;i++) if (A[i]==0) zeros++;
    dbg(N,A);

    int off = 0;
    for (int i=0;i<(N+1)/2;i++){
        if (A[i]!=A[N-1-i]) off++;
    }

    bool mid0 = (N%2==1 && A[N/2]==0);

    //CASE 1: starts paly
    if (off==0){
        if (zeros%2==0 || zeros==1) cout << "BOB" << endl;
        else cout << "ALICE" << endl;
    }
    //CASE 2: mid0 and 1 off
    else if (mid0 && off==1 && zeros==2){
        cout << "DRAW" << endl;
    }
    //CASE 3: else
    else {
        cout << "ALICE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}