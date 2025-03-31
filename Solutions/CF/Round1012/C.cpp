#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int cost(pair<int,int> p){
    return p.first + p.second + 2*(p.first%3==2 && p.second%3==2);
}
bool special(pair<int,int> p){
    return p.first%3==1 && p.second%3==1;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int i=0;i<n;i++) cin >> a[i];

    int k = ceil(sqrt(2*n));
    vector<pair<int,int>> cells;
    for (int x=0;x<k;x++){
        for (int y=0;y<k;y++){
            cells.push_back({3*x+1,3*y+1});
            cells.push_back({3*x+1,3*y+2});
            cells.push_back({3*x+2,3*y+1});
            cells.push_back({3*x+2,3*y+2});
        }
    }
    // dbg(cells);
    sort(begin(cells), end(cells), [](pair<int,int> a, pair<int,int> b){
        if (cost(a) != cost(b)) return cost(b) > cost(a);
        if (a.first != b.first) return b.first > a.first;
        return b.second > a.second;
    });
    dbg(cells);
    vector<bool> vis(cells.size());
    int ptr0 = 0;
    int ptr1 = 0;
    for (int i=0;i<n;i++){
        if (a[i]==1){
            while (vis[ptr0]) ptr0++;
            vis[ptr0] = true;
            cout << cells[ptr0].first << " " << cells[ptr0].second << nl;
        }else{
            while (vis[ptr1] || !special(cells[ptr1])) ptr1++;
            vis[ptr1] = true;
            cout << cells[ptr1].first << " " << cells[ptr1].second << nl;
        }
    }
}
int main() {
    int t; cin >> t; while (t--){
        solve();
    }
}