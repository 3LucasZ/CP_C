#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<pair<int,int>> gaps(n);
    for (int i=0;i<n;i++){
        cin >> gaps[i].first >> gaps[i].second;
    }
    queue<pair<int,int>> jmps;
    for (int i=0;i<m;i++){
        pair<int,int> x; cin >> x.first >> x.second;
        jmps.push(x);
    }
    priority_queue<int> use;

    int tk = 0;
    int mxGapSize = 1;
    for (int i=0;i<n;i++){
        int gapSize = gaps[i].second - gaps[i].first + 2;
        while (!jmps.empty() && jmps.front().first < gaps[i].first){
            use.push(jmps.front().second);
            jmps.pop();
        }
        while (mxGapSize < gapSize) {
            if (use.empty()){
                cout << -1 << endl;
                return;
            }
            tk++;
            mxGapSize += use.top();
            use.pop();
        }
    }
    cout << tk << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}