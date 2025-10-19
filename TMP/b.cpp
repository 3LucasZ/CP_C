#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};
int main()
{
    int R, C, n;
    cin >> R >> C >> n;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(R, vector<int>(C));
    vector<vector<int>> vis2(R, vector<int>(C));
    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        vis[r][c] = i + 1;
        q.push({r, c});
    }
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            pair<int, int> next = {cur.first + dr[d], cur.second + dc[d]};
            // out of bounds
            if (next.first < 0 || next.first >= R || next.second < 0 || next.second >= C)
                continue;
            // vis1 not found
            if (!vis[next.first][next.second])
            {
                vis[next.first][next.second] = vis[cur.first][cur.second];
                q.push(next);
                continue;
            }
            // vis2 not found
            if (!vis2[next.first][next.second])
            {
                // different visitor
                if (vis[next.first][next.second] != vis[cur.first][cur.second])
                {
                    vis2[next.first][next.second] = vis[cur.first][cur.second];
                }
            }
            // vis2 found
            else
            {
                // different visitor
                // if (vis[next.first][next.second] != vis[cur.first][cur.second])
                // {
                //     vis2[next.first][next.second] = min(vis2[next.first][next.second], vis[cur.first][cur.second]);
                // }
            }
        }
    }

    // for (int r = 0; r < R; r++)
    // {
    //     for (int c = 0; c < C; c++)
    //     {
    //         cout << vis[r][c] << " ";
    //     }
    //     cout << nl;
    // }
    // dbg();

    // for (int r = 0; r < R; r++)
    // {
    //     for (int c = 0; c < C; c++)
    //     {
    //         cout << vis2[r][c] << " ";
    //     }
    //     cout << nl;
    // }
    // dbg();

    queue<pair<int, int>> q2;
    vector<vector<pair<int, int>>> pts(n + 1);
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (vis2[r][c])
            {
                pts[vis2[r][c]].push_back({r, c});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto p : pts[i])
        {
            q2.push(p);
        }
    }
    while (!q2.empty())
    {
        pair<int, int> cur = q2.front();
        q2.pop();
        for (int d = 0; d < 4; d++)
        {
            pair<int, int> next = {cur.first + dr[d], cur.second + dc[d]};
            // out of bounds
            if (next.first < 0 || next.first >= R || next.second < 0 || next.second >= C)
                continue;
            // vis2 found
            if (vis2[next.first][next.second])
                continue;
            // vis2 not found
            else
            {
                vis2[next.first][next.second] = vis2[cur.first][cur.second];
                q2.push(next);
            }
        }
    }
    // for (int r = 0; r < R; r++)
    // {
    //     for (int c = 0; c < C; c++)
    //     {
    //         cout << vis2[r][c] << " ";
    //     }
    //     cout << nl;
    // }
    // dbg();

    // ANSWER
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cout << vis[r][c] << " ";
        }
        cout << nl;
    }
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cout << vis2[r][c] << " ";
        }
        cout << nl;
    }
    cout << nl;
}