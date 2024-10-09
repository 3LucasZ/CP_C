#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
const char nl = '\n';
const vector<int> dr = {0,0,1,-1};
const vector<int> dc = {1,-1,0,0};

int R,C;
pair<int,int> s;
pair<int,int> t;
vector<pair<int,int>> trees;
vector<vector<int>> weight;

bool ok(int w) {
    dbg(w);
    if (weight[s.first][s.second]<w) return false;
    vector<vector<bool>> vis(R, vector<bool>(C));
    vis[s.first][s.second] = true;
    deque<pair<int, int>> dq;
    dq.push_back({s.first,s.second});

    while(dq.size()>0){
        pair<int,int> cur = dq.front(); dq.pop_front();
        for (int i=0;i<4;i++){
            pair<int,int> nxt = {cur.first+dr[i],cur.second+dc[i]};
            if (nxt.first >=0 && nxt.first < R && nxt.second >=0 && nxt.second < C && !vis[nxt.first][nxt.second] && weight[nxt.first][nxt.second] >= w){
                vis[nxt.first][nxt.second] = true;
                dq.push_back(nxt);
            }
        }
    }
    for (int i=0;i<R;i++) dbg(vis[i]);
    dbg();
    return vis[t.first][t.second];
}

int main(){
    cin >> R >> C;
    for (int r=0;r<R;r++){
        string row; cin >> row;
        for (int c=0;c<C;c++){
            char x = row[c];
            if (x=='V') s = {r,c};
            else if (x=='J') t = {r,c};
            else if (x=='+') trees.push_back({r,c});
        }
    }

    //precomp 
    //setup
    weight.resize(R, vector<int>(C));
    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            weight[r][c] = -1;
        }
    }
    deque<pair<int, int>> dq;
    for (auto tree : trees){
        dq.push_back(tree);
        weight[tree.first][tree.second] = 0;
    }
    //bfs
    while (dq.size() > 0){
        pair<int,int> cur = dq.front(); dq.pop_front();
        for (int i=0;i<4;i++){
            pair<int,int> nxt = {cur.first+dr[i],cur.second+dc[i]};
            if (nxt.first >=0 && nxt.first < R && nxt.second >=0 && nxt.second < C && weight[nxt.first][nxt.second] == -1){
                weight[nxt.first][nxt.second] = weight[cur.first][cur.second] + 1;
                dq.push_back(nxt);
            }
        }
    }
    for (int i=0;i<R;i++) dbg(weight[i]);

    //binsrch
    int lo=0; int hi=R*C;
    while (lo<hi){
        int mid = lo + ((hi - lo + 1) >> 1); //weight we will try to floodfill on
        if (ok(mid)){
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << nl;
}