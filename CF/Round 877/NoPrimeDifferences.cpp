#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue> 

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
bool multi = true;
bool dbg = true;

const int MAXN = 1000;
const int MAXM = 1000;
int ret[MAXN][MAXM];

void solve(){
    int N,M; cin >> N >> M;
    int cur = 1;
    for (int i=1;i<N;i+=2){
        for (int j=0;j<M;j++){
            ret[i][j]=cur;
            cur++;
        }
    }
    for (int i=0;i<N;i+=2){
        for (int j=0;j<M;j++){
            ret[i][j]=cur;
            cur++;
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) solve();
    return 0;
}