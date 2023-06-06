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
bool multi = true;
bool dbg = true;

void solve(){
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