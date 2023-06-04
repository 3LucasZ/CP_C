#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second

const int MOD = 1000000007;
bool multi = true;
bool dbg = true;

void solve(){
    int N;
    cin >> N;
    vector<pi> lamps(N);
    for (int i=0;i<N;i++){
        cin >> lamps[i].f >> lamps[i].s;
    }
    sort(lamps.begin(), lamps.end());
    if (dbg){
        for (int i=0;i<N;i++){
            cout << lamps[i].f << ", " << lamps[i].s << endl;
        }
    }

}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for (int i=0;i<T;i++) solve();
    return 0;
}