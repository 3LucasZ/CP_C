#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
unordered_map<char, int> mp = {{'N',0},{'E',2},{'S',1},{'W',3}};
void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    dbg(n,a,b,s);
    int x = 0, y = 0;
    for (int i=0;i<20;i++){
        for (int j=0;j<n;j++){
            x += dx[mp[s[j]]];
            y += dy[mp[s[j]]];
            // dbg(x,y);
            if (x==a && y==b) {
                cout << "YES" << nl;
                return;
            }
        }
    }
    cout << "NO" << nl;
}
int main() {
    int t; cin >> t; 
    while (t--) solve();
}