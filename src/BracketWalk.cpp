#include <iostream>
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
#define ins insert

const int MOD = 1000000007;
bool multi = false;
bool dbg = true;

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}

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
    if (dbg){
        for (int i=0;i<=N+1;i++){
            cout << A[i] << ", ";
        }
        cout << endl;
    }
    set<int> open2;
    set<int> close2;
    for (int i=1;i<=N;i++){
        if (A[i]==A[i+1]==0){
            open2.insert(i);
        } else if (A[i]==A[i+1]==1){
            close2.insert(i);
        }
    }

    //handle q
    for (int i=0;i<Q;i++){
        int cur; cin >> cur;
        if (A[cur]==A[cur-1]==0) open2.erase(cur-1);
        if (A[cur]==A[cur+1]==0) open2.erase(cur);
        if (A[cur]==A[cur-1]==1) close2.erase(cur-1);
        if (A[cur]==A[cur+1]==1) close2.erase(cur);
        A[cur]=1-A[cur];
        if (A[cur]==A[cur-1]==0) open2.insert(cur-1);
        if (A[cur]==A[cur+1]==0) open2.insert(cur);
        if (A[cur]==A[cur-1]==1) close2.insert(cur-1);
        if (A[cur]==A[cur+1]==1) close2.insert(cur);
        cout << open2 << endl;
        if (N%2==1 || open2.empty() != open2.empty()) {
            cout << "NO" << endl;
            continue;
        }
        if (*--open2.end() < *--close2.end() && *open2.begin() < *close2.begin()) {
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