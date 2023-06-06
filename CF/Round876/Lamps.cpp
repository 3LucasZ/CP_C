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

#define f first
#define s second

const int MOD = 1000000007;
bool multi = true;
bool dbg = false;

void solve(){
    int N; 
    cin >> N;
    vector<pi> lamps(N);
    for (int i=0;i<N;i++){
        cin >> lamps[i].f >> lamps[i].s;
        lamps[i].s*=-1;
    }
    //sort by f from lo to hi, then b from hi to lo
    sort(lamps.begin(), lamps.end());
    for (int i=0;i<N;i++){
        lamps[i].s*=-1;
    }
    if (dbg){
        for (int i=0;i<N;i++){
            cout << lamps[i].f << ", " << lamps[i].s << endl;
        }
    }
    //sim
    ll ans = 0;
    priority_queue<int> onLamps;
    
    int max_sz = 0;
    for (int i=0;i<N;i++){
        if (lamps[i].f <= max_sz) continue;

        ans+=lamps[i].s;
        onLamps.push(-lamps[i].f);
        int cur_sz = onLamps.size();
        max_sz=max(max_sz,cur_sz);
        while (onLamps.size()>0 && -onLamps.top()<=cur_sz) onLamps.pop();
    }

    //ret
    cout << ans << endl;
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for (int i=0;i<T;i++) solve();
    return 0;
}