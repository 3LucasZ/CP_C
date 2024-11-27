#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;

ll n, m, k;
vector<ll> hh;
vector<ll> x;

bool solveMoves(ll moves) {
    vector<ll> h(n);
    for (int i=0;i<n;i++){
        h[i]=(hh[i]+moves-1)/moves;
    }
    // dbg(moves, h);

    // create intervals
    vector<pair<ll,int>> events;
    for (int i=0;i<n;i++){ 
        // position, id
        ll range = max(m-h[i], 0LL);
        if (m < h[i]) continue;
        events.push_back({x[i]-range,-(i+1)});
        events.push_back({x[i]+range,(i+1)});
    }

    // sort intervals
    sort(all(events));
    // dbg(events);

    //process intervals
    int active = 0;
    for (pair<long,int> event : events){
        // open
        if (event.second < 0) {
            active++;
        } 
        // close
        else {
            active--;
        }
        if (active >= k) return true;
    }
    return false;
}
void solve() {
    cin >> n >> m >> k;
    dbg(n,m,k);
    hh.resize(n);
    for (int i=0;i<n;i++){
        cin >> hh[i];
    }
    x.resize(n);
    for (int i=0;i<n;i++){
        cin >> x[i];
    }
    ll mx = 1e9+1;
    ll lo=1; ll hi=mx;
    while (lo<hi){
        // # moves to try
        ll mid = (lo+hi)/2;
        if (solveMoves(mid)){
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    // solveMoves(6969697);
    if (lo==mx) cout << -1 << endl;
    else cout << lo << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}