#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int cnt(vector<vector<char>> &grid, int n, int i, int j)
{
    int ret = 0;
    for (int k = 0; k < 4; k++)
    {
        int i2 = i + dx[k];
        int j2 = j + dy[k];
        if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= n)
            continue;
        if (grid[i2][j2] == '?')
            ret++;
    }
    return ret;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j];
        }
    }
    bool bad = false;

    vector<vector<bool>> lit(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != '?')
                continue;
            for (int k = 0; k < 4; k++)
            {
                for (int l = 1; l < n; l++)
                {
                    int i2 = i + dx[k] * l;
                    int j2 = j + dy[k] * l;
                    if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= n)
                        break;
                    if (grid[i2][j2] != '.')
                    {
                        if (grid[i2][j2] == '?')
                            bad = true;
                        break;
                    }

                    lit[i2][j2] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = cnt(grid, n, i, j);
            // dbg(i, j, c);
            if (grid[i][j] == '.' && lit[i][j] == false)
                bad = true;
            if (grid[i][j] == '0' && c != 0)
                bad = true;
            if (grid[i][j] == '1' && c != 1)
                bad = true;
            if (grid[i][j] == '2' && c != 2)
                bad = true;
            if (grid[i][j] == '3' && c != 3)
                bad = true;
            if (grid[i][j] == '4' && c != 4)
                bad = true;
            // if (bad == true)
            //     dbg("BAD");
        }
    }
    if (bad)
    {
        cout << 0 << nl;
    }
    else
    {
        cout << 1 << nl;
    }
}