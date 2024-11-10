#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int R, C;
vector<vector<int>> a;
vector<pair<int,int>> a_loc;
vector<vector<int>> b;
vector<pair<int,int>> b_loc;
vector<vector<int>> mvs;

void swp(int r1, int c1, int r2, int c2) {
    swap(a[r1][c1], a[r2][c2]);
    swap(a_loc[a[r1][c1]], a_loc[a[r2][c2]]);
    mvs.push_back({r1,c1,r2,c2});
}

int main() {
    //in
    cin >> R >> C;
    a.resize(R+1, vector<int>(C+1));
    a_loc.resize(R*C+1);
    b.resize(R+1, vector<int>(C+1));
    b_loc.resize(R*C+1);
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            cin >> a[i][j];
            a_loc[a[i][j]]={i,j};
        }
    }
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++){
            cin >> b[i][j];
            b_loc[b[i][j]]={i,j};
        }
    }
    dbg(a);
    dbg(b);

    //work
    for (int x=1;x<=R*C;x++){
        pair<int,int> src = a_loc[x];
        pair<int,int> snk = b_loc[x];
        int y = a[snk.first][snk.second];
        //Case 1:
        if (src.first == snk.first) continue;
        //Case 2A:
        else if (src.second==C || y < a[src.first][src.second+1]) swp(src.first, src.second, snk.first, snk.second);
        //Case 2B (tough):
        else {
            while (y > a[src.first][src.second+1]) {
                for (int c=src.second;c<=C;c++){
                    if (c==C || y < a[src.first][c+1]) {
                        swp(src.first, c, snk.first, snk.second);
                        break;
                    }
                }
                y = a[snk.first][snk.second];
            }
            swp(src.first, src.second, snk.first, snk.second);
        }
    }

    //ret
    cout << mvs.size() << nl;
    for (auto mv : mvs) {
        for (auto item : mv) {
            cout << item << " ";
        }
        cout << nl;
    }
}