#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end()

int L, W, N, R;
int main() {
    //input; multiply R, x, y by 2 to avoid floats
    cin >> L >> W >> N >> R; R*=2;
    vector<pair<int,int>> points {{L,0},{-L,0},{0,W},{0,-W}};
    dbg(N,R,points);
    unordered_set<int> can;
    unordered_set<int> bigCan;
    for (int i=0;i<N;i++){
        int x, y; cin >> x >> y; x*=2, y*=2;
        int cur = 0;
        for (int j=0;j<4;j++){
            int dist = pow(points[j].first-x,2) + pow(points[j].second-y,2);
            if (dist <= R*R){
                cur += (1<<j);
            }
        }
        can.insert(cur);
        bigCan.insert(cur);
    }
    for (int ans=1;ans<=4;ans++){
        if (bigCan.count(15)) {
            cout << ans << nl;
            return 0;
        }
        unordered_set<int> tmp;
        for (auto i : bigCan){
            for (auto j : can){
                tmp.insert(i|j);
            }
        }
        bigCan = tmp;
    }
    cout << "Impossible" << nl;
}