#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
const int MAXN = 500;
int arr[MAXN][MAXN];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
void solve()
{
    int n;
    cin >> n;
    int step = 0;
    int stepsz = 1;
    int dir = 0;
    int r = (n - 1) / 2;
    int c = (n - 1) / 2;
    dbg(n * n);
    arr[r][c] = 0;
    c++;
    for (int i = 1; i < n * n; i++)
    {
        dbg(r, c, dir, step);
        arr[r][c] = i;
        step++;
        if (step >= stepsz)
        {
            if (dir % 2 == 1)
                stepsz++;
            dir = (dir + 1) % 4;
            step = 0;
        }
        r = r + dr[dir];
        c = c + dc[dir];
    }
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}