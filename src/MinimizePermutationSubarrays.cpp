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

void solve(){
    int N; cin >> N;
    int id1, id2, idN;
    for (int i=1;i<=N;i++) {
        int cur; cin >> cur;
        if (cur==1) id1 = i;
        if (cur==2) id2 = i;
        if (cur==N) idN = i;
    }
    if (id2 < id1){
        int tmp = id1;
        id1=id2;
        id2=tmp;
    }
    if (idN<id1){
        cout << id1 << " " << idN;
    }
    else if (idN>id2){
        cout << id2 << " " << idN;
    } else {
        cout << 1 << " " << 1;
    }
    cout << endl;
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) solve();
    return 0;
}