#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue> 
#include <set>
#include <string>
#include <sstream>

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
#define ins insert

//const int MOD = 1000000007;
bool multi = false;
bool dbg = false;

template<typename T, typename V>
string toString(const pair<T, V> &x) {stringstream ret; ret << "{" << x.f << ", " << x.s << '}'; return ret.str();}
template<typename T>
string toString(const T &x) {int f = 0; stringstream ret; ret << "{"; for (auto &i: x) ret << (f++ ? ", " : "") << i; ret << "}"; return ret.str();}

void solve(){
    int N,Q; cin >> N >> Q;
    //let 0 -> ( and let 1 -> )
    vi A(N+2);
    A[0]=-1; A[N+1]=-1;
    for (int i=1;i<=N;i++){
        char cur; cin >> cur;
        if (cur=='('){
            A[i]=0;
        } else {
            A[i]=1;
        }
    }
    set<int> open2;
    set<int> close2;
    for (int i=1;i<=N;i++){
        if (A[i]==A[i+1] && A[i]==0){
            open2.ins(i);
        } else if (A[i]==A[i+1] && A[i]==1){
            close2.ins(i);
        }
    }
    if (dbg){
        cout << "INIT"  << endl;
        cout << "A:" << toString(A) << endl;
        cout << "open2:" <<toString(open2) << endl;
        cout << "close2:" <<toString(close2) << endl;
        cout << "EOF" << endl;
    }

    //handle q
    for (int i=0;i<Q;i++){
        int cur; cin >> cur;
        if (A[cur]==0){
            if (A[cur]==A[cur-1]) open2.erase(cur-1);
            if (A[cur]==A[cur+1]) open2.erase(cur);
        } else {
            if (A[cur]==A[cur-1]) close2.erase(cur-1);
            if (A[cur]==A[cur+1]) close2.erase(cur);
        }
        A[cur]=1-A[cur];
        if (A[cur]==0){
            if (A[cur]==A[cur-1]) open2.ins(cur-1);
            if (A[cur]==A[cur+1]) open2.ins(cur);
        } else {
            if (A[cur]==A[cur-1]) close2.ins(cur-1);
            if (A[cur]==A[cur+1]) close2.ins(cur);
        }
        if (dbg){
            cout << "A:" << toString(A) << endl;
            cout << "open2:" <<toString(open2) << endl;
            cout << "close2:" <<toString(close2) << endl;
        }
        if (N%2==1 || open2.empty() != close2.empty() || A[1]==1 || A[N]==0) {
            cout << "NO" << endl;
        }
        else if (open2.empty() && close2.empty()){
            cout << "YES" << endl;
        }
        else if (*--open2.end() < *--close2.end() && *open2.begin() < *close2.begin()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) {
        if (dbg) cout << "CASE: " << i+1 << endl;
        solve();
    }
    return 0;
}