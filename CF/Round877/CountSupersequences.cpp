#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue> 
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
template<class T> using pq = priority_queue<T>;

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

template<typename T, typename V>
string toString(const pair<T, V> &x) {stringstream ret; ret << "{" << x.f << ", " << x.s << '}'; return ret.str();}
template<typename T>
string toString(const T &x) {int f = 0; stringstream ret; ret << "{"; for (auto &i: x) ret << (f++ ? ", " : "") << i; ret << "}"; return ret.str();}

const bool multi = true;
const bool dbg = false;
const ll MOD = 1e9+7;

//a ^ b
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

void solve(){
    int N,M,K; cin >> N >> M >> K;
    int A[N]; for (int i=0;i<N;i++) cin >> A[i];
    ll ret = po(K,M);
    ll chs = 1;
    for (int i=0;i<=N-1;i++){
        ret = ret-chs*po(K-1,M-i)%MOD;
        chs = chs*(M-(i+1)+1)%MOD*po(i+1,MOD-2)%MOD;
    }
    cout << (ret%MOD+MOD)%MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) {
        if (dbg) cout << "CASE: " << i+1 << endl;
        solve();
    }
    return 0;
}