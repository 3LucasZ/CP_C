// NOTE:
// I got the main idea and algorithm correct.
// Couldn't finish the implementation since it has been taking a while.
// I read the editorial after solving and I have everything logically correct.
// Will come back to it another day!

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
vector<bool> mustRow;
vector<bool> mustCol;

bool dfs(int i, int color) {
    if (vis[i]<color) return true;
    if (vis[i]==color) return false;
    vis[i]=color;
    // handle rows
    if (i<R) {
        for (int j=0;j<C;j++){
            if (b[i][j]==1) {
                if (dfs(R+j, color)==false) return false;
            }
        }
    }
    // handle cols 
    else {
        i-=R;
        for (int j=0;j<R;j++){
            if (b[j][i]==0) {
                if (dfs(j, color)==false) return false;
            }
        }
    }
    return true;
}
bool ok(int bit) {
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            a[i][j]=(A[i][j]&(1<<bit))==0?0:1;
            b[i][j]=(B[i][j]&(1<<bit))==0?0:1;
        }
    }

    mustRow.clear(); mustRow.resize(R);
    mustCol.clear(); mustCol.resize(C);
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            if (a[i][j]==1 && b[i][j]==0) {
                mustRow[i] = true;
            }
            if (a[i][j]==0 && b[i][j]==1) {
                mustCol[i] = true;
            }
        }
    }
    
    // dbg(colOps, rowOps);
    vis.clear(); vis.resize(R+C, INT_MAX);
    int color = 1;
    for (int i=0;i<R;i++){
        if (mustRow[i] && dfs(i, color) == false) return false;
        color++;
    }
    for (int i=0;i<C;i++){
        if (mustCol[i] && dfs(R+i, color) == false) return false;
        color++;
    }
    return true;
}

// boilerplate
void solve() {
    cin >> R >> C;
    A.clear(); A.resize(R,vector<int>(C));
    B.clear(); B.resize(R,vector<int>(C));
    a.clear(); a.resize(R,vector<int>(C));
    b.clear(); b.resize(R,vector<int>(C));
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