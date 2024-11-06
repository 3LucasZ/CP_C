#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int R, C;
vector<pair<int,int>> loc;
vector<vector<int>> a;

vector<vector<int>> mvs1;
vector<vector<int>> mvs2;

void swp(int r1, int c1, int r2, int c2) {
    swap(a[r1][c1], a[r2][c2]);
    swap(loc[a[r1][c1]], loc[a[r2][c2]]);
    mvs1.push_back({r1,c1,r2,c2});
}

void fix(int r, int c){
    int tar = (c-1)*R+r;
    while (a[r][c]>tar){
        swp(r, c, loc[a[r][c]-1].first, loc[a[r][c]-1].second);
    }
}

void create() {
    dbg();
    for (int r=1;r<=R;r++){
        for (int c=1;c<=C;c++){
            int x; cin >> x;
            loc[x] = {r,c};
            a[r][c]=x;
        }
    }
    dbg(loc);
    for (int r=1;r<=R;r++){
        dbg(a[r]);
    }

    for (int c=1;c<=C;c++){
        for (int r=1;r<=R;r++){
            fix(r,c);
        }
    }
    dbg(loc);
    for (int r=1;r<=R;r++){
        dbg(a[r]);
    }
    
    swap(mvs1,mvs2);
}

int main() {
    cin >> R >> C;
    loc.resize(R*C+1);
    a.resize(R+1, vector<int>(C+1));

    for (int i=0;i<2;i++) {
        create();
    }

    dbg(mvs1);
    dbg(mvs2);
    reverse(all(mvs2));
    for (auto x : mvs2) mvs1.push_back(x);
    dbg(mvs1);

    //ret
    cout << mvs1.size() << nl;
    for (auto mv : mvs1){
        for (auto item : mv) {
            cout << item << " ";
        }
        cout << nl;
    }
}