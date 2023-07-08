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

const bool multi = false;












ll nth_bit(ll num, int bit){ return (num&(1<<bit))>0;}
vector<int> v_xor(vector<int> &v, int num){
    vector<int> ret;
    for (int i : v) ret.push_back(i^num);
    return ret;
}
ll invs(vector<int> &v, int pick){
    ll ones = 0; ll ret = 0;
    for (int i : v){
        if (i==pick) ones++;
        else ret+=ones;
    }
    return ret;
}

int N;
vector<ll> A;
ll best_x;
ll best_invs;

ll solveBitPart1(int bit, int q, vector<int> &ids){
    //create vbit
    vector<int> vbit;
    for (int i : ids) vbit.push_back(nth_bit(A[i],bit));
    //try q
    ll a_invs = invs(vbit, 1-q);
    //propagate
    return a_invs;
}
tuple<vector<int>,vector<int>> solveBitPart2(int bit, int q, vector<int> &ids){
     //create vbit
    vector<int> vbit;
    for (int i : ids) vbit.push_back(nth_bit(A[i],bit));
    //propagate
    vector<int> ids0;
    vector<int> ids1;
    for (int i=0;i<sz(vbit);i++){
        if (vbit[i]==0) ids0.push_back(ids[i]);
        else ids1.push_back(ids[i]);
    }
    return {ids0,ids1};
}
void solveBit(int bit, vector<vector<int>> &partIds){
    //protect
    if (bit < 0) return;
    dbg(bit,partIds);
    //try q = 0 and 1
    ll invs0 = 0; ll invs1 = 0;
    for (vector<int> &ids : partIds){
        //try q=0
        ll a_invs = solveBitPart1(bit, 0, ids);
        invs0+=a_invs;
        //try q=1
        ll b_invs = solveBitPart1(bit, 1, ids);
        invs1+=b_invs;
    }
    dbg(invs0, invs1);
    //judge + update ans
    int pick;
    if (invs0<=invs1) pick=0;
    else pick=1;
    best_x += (pick<<bit);
    best_invs += min(invs0,invs1);
    //propagate
    vector<vector<int>> nextPartIds;
    for (vector<int> &ids : partIds){
        auto [a_ids0,a_ids1] = solveBitPart2(bit, pick, ids);
        if (sz(a_ids0)>1) nextPartIds.push_back(a_ids0);
        if (sz(a_ids1)>1) nextPartIds.push_back(a_ids1);
    }
    solveBit(bit-1,nextPartIds);
}
void solve(){
    cin >> N;
    A.clear();A.resize(N);
    for (int i=0;i<N;i++) cin >> A[i];
    dbg(N,A);
    best_x = 0;
    best_invs = 0;

    vector<vector<int>> initIds(1); for (int i=0;i<N;i++) initIds[0].push_back(i);
    solveBit(31,initIds);
    
    cout << best_invs << " " << best_x << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}