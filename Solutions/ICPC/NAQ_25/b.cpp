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
    // setup BFS queue
    int R, C, n;
    cin >> R >> C >> n;
    queue<tuple<int, int, int>> q;
    vector<vector<int>> vis(R, vector<int>(C));
    vector<vector<int>> vis2(R, vector<int>(C));
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        vis[r][c] = i;
        q.push({r, c, i});
    }

    // BFS
    while (!q.empty())
    {
        auto [r, c, i] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int r2 = r + dr[d];
            int c2 = c + dc[d];
            // out of bounds
            if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C)
                continue;
            // already seen before
            if (vis[r2][c2] == i || vis2[r2][c2] == i)
                continue;
            // vis1 not found
            if (!vis[r2][c2])
            {
                vis[r2][c2] = i;
            }
            // vis2 not found
            else if (!vis2[r2][c2])
            {
                vis2[r2][c2] = i;
            }
            else
            {
                continue;
            }
            q.push({r2, c2, i});
        }
    }

    // print vis, vis2
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