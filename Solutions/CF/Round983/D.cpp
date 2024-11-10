#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int q(int u, int v){
    cout << "? " << u << " " << v << endl;
    int x; cin >> x;
    return x;
}
void solve() {
    int n; cin >> n;
    vector<int> p(n, -1);
    list<int> heads = {1};

    //create heads
    p[1] = 0;
    for (int u=2;u<n;u++){
        if (q(u, 1)==0) break;
        heads.push_back(u);
        p[u] = 0;
    }
    //create tails
    int tmp = heads.back()+1;
    p[tmp] = heads.front();
    heads.pop_front();
    heads.push_back(tmp);
    for (int u=tmp+1;u<n;u++) {
        while (q(u, heads.front())==1) {
            heads.pop_front();
        }
        p[u] = heads.front();
        heads.pop_front();
        heads.push_back(u);
    }
    //ret
    cout << "! ";
    for (int i=1;i<n;i++){
        cout << p[i] << " ";
    }
    cout << endl;
}
int main() {
    int T; cin >> T; while (T--) solve();
}