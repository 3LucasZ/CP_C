#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

struct State
{
    int r, c, d;
};
vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};
bool validState(State s, int R, int C, vector<vector<bool>> &blocked)
{
    int r = s.r;
    int c = s.c;
    return !(r < 0 || c < 0 || r >= R || c >= C || blocked[r][c]);
}
int main()
{
    int R, C;
    cin >> R >> C;
    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> start.second >> end.first >> end.second;
    start.first--;
    start.second--;
    end.first--;
    end.second--;
    vector<vector<bool>> blocked(R, vector<bool>(C));
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            blocked[i][j] = s[j] == '1';
        }
    }
    dbg(R, C, start, end);
    dbg(blocked);

    vector<vector<vector<bool>>> vis(R, vector<vector<bool>>(C, vector<bool>(4)));
    vis[start.first][start.second][0] = true;
    queue<State> q;
    q.push({start.first, start.second, 0});
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        vector<int> ds = {{cur.d - 1 < 0 ? 3 : cur.d - 1, cur.d, cur.d + 1 > 3 ? 0 : cur.d + 1}};
        for (int d : ds)
        {
            State next = {cur.r + dr[d], cur.c + dc[d], d};
            if (d == ds[2])
                next = {cur.r, cur.c, d};
            if (validState(next, R, C, blocked))
            {
                // dbg(next.r, next.c, next.d);
                if (!vis[next.r][next.c][next.d])
                {
                    vis[next.r][next.c][next.d] = true;
                    q.push(next);
                }
                break;
            }
        }
    }

    // ret
    bool ok = false;
    for (int i = 0; i < 4; i++)
    {
        if (vis[end.first][end.second][i])
            ok = true;
    }
    cout << (int)ok << nl;
}