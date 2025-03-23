// Gave up and read the editorial
// https://codeforces.com/blog/entry/137801

#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

vector<vector<int>> A;
vector<vector<int>> B;
vector<vector<int>> a;
vector<vector<int>> b;
int R, C;
vector<int> vis;

struct graph {
    int V;
    vector<vector<int>> g;
    vector<int> color;
    graph(int V){
        this->V = V;
        this->g.resize(V);
        this->color.resize(V);
    };
    void add(int u, int v) {
        g[u].push_back(v);
    }
    bool isLoop(int u){
        if (color[u]!=0) return false;
        color[u] = 1;
        bool ret = false;
        for (int v : g[u]){
            if (color[v]==2) continue;
            else if (color[v]==0) ret |= isLoop(v);
            else ret = true;
        }
        color[u] = 2;
        return ret;
    }
};

bool ok(int bit) {
    //fixate arrays a and b onto given bit
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            a[i][j]=(A[i][j]>>bit)&1;
            b[i][j]=(B[i][j]>>bit)&1;
        }
    }

    vector<bool> mustRow(R);
    vector<bool> mustCol(C);
    auto G = graph(R+C);

    // find the operations you need to use 
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            // use & operation on row i
            if (a[i][j]==1 && b[i][j]==0) {
                mustRow[i] = true;
            }
            // use | operation on column j
            if (a[i][j]==0 && b[i][j]==1) {
                mustCol[j] = true;
            }
            // add edge to graph if another operation must be applied after this operation
            // this happens if our operations messes up other nodes
            if (b[i][j]==0) G.add(j+R, i);
            else G.add(i, j+R);
        }
    }
    
    // check if any operators creates a cycle
    for (int i=0;i<R;i++){
        if (mustRow[i] && G.isLoop(i)) return false;
    }
    for (int j=0;j<C;j++){
        if (mustCol[j] && G.isLoop(j+R)) return false;
    }
    return true;
}

void solve() {
    // dimensions
    cin >> R >> C;
    // main input arrays
    A.clear(); A.resize(R,vector<int>(C));
    B.clear(); B.resize(R,vector<int>(C));
    // temporary bit-focused arrays
    a.clear(); a.resize(R,vector<int>(C));
    b.clear(); b.resize(R,vector<int>(C));
    //input
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> A[i][j];
        }
    }
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            cin >> B[i][j];
        }
    }
    //check that each bit [0-30] when focused is ok
    for (int i=0;i<=30;i++){
        if (ok(i) == false) {
            cout << "No" << nl;
            return;
        }
    }
    cout << "Yes" << nl;
}
int main() {
    int t; cin >> t; 
    for (int i=0;i<t;i++) solve();
}