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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    dbg(N,A);

    vector<vector<int>> ids(N+1);
    for (int i=0;i<N;i++){
        ids[A[i]].push_back(i);
    }
    dbg(ids);

    vector<vector<int>> windowNums(N+1);
    for (int num=1;num<=N;num++){ //i is the dig we are iterating on 
        dbg(num);
        vector<int> numIds = ids[num];
        if (sz(numIds)==0) continue;
        int maxCover = max(numIds[0], N-1-numIds[sz(numIds)-1]);
        dbg(maxCover);
        for (int id=1;id<sz(numIds);id++){ //j is the index of the dig in A we are iterating on
            int dist = numIds[id]-numIds[id-1]-1;
            int cover = (dist+1)/2;
            maxCover=max(maxCover,cover);
        }
        windowNums[maxCover+1].push_back(num);
    }
    dbg(windowNums);

    int ans = 10*N;
    for (int window=1;window<=N;window++){
        for (int j : windowNums[window]) ans=min(ans,j);
        if (ans==10*N) cout << -1;
        else cout << ans;
        cout << " ";
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