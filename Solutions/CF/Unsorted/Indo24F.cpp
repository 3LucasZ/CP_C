#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int R, C, X;
    cin >> R >> C >> X;
    vector<vector<int>> a(R + 1, vector<int>(C + 1));
    for (int r = 1; r <= R; r++)
    {
        string s;
        cin >> s;
        for (int c = 1; c <= C; c++)
        {
            a[r][c] = s[c - 1] - '0';
        }
    }
    dbg(a);
    int Q;
    cin >> Q;
    // check every mini-cycle
    bool good = true;
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    for (int r = 1; r <= R - 1; r++)
    {
        for (int c = 1; c <= C - 1; c++)
        {
            int r0 = r, c0 = c;
            ll sum = 0;
            for (int i = 0; i < 4; i++)
            {
                int r1 = r0 + dr[i];
                int c1 = c0 + dc[i];
                sum += pow(a[r0][c0] - a[r1][c1], X);
                r0 = r1;
                c0 = c1;
            }
            if (sum != 0)
                good = false;
        }
    }
    dbg(good);
    // presums
    vector<vector<ll>> rsum(R + 1, vector<ll>(C + 1));
    vector<vector<ll>> csum(R + 1, vector<ll>(C + 1));
    for (int r = 1; r <= R; r++)
        for (int c = 1; c <= C; c++)
        {
            if (c > 1)
                rsum[r][c] = rsum[r][c - 1] + pow(a[r][c - 1] - a[r][c], X);
            if (r > 1)
                csum[r][c] = csum[r - 1][c] + pow(a[r - 1][c] - a[r][c], X);
        }
    dbg(rsum);
    dbg(csum);
    // find any arbitrary path
    for (int i = 0; i < Q; i++)
    {
        dbg(i);
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;

        if (!good)
        {
            cout << "INVALID" << nl;
            continue;
        }
        ll sum = 0;
        int mul = 1;
        if (r1 < r0)
        {
            swap(r0, r1);
            swap(c0, c1);
            mul *= -1;
        }
        sum += mul * (csum[r1][c0] - csum[r0][c0]);
        r0 = r1;
        if (c1 < c0)
        {
            swap(r0, r1);
            swap(c0, c1);
            mul *= -1;
        }
        sum += mul * (rsum[r1][c1] - rsum[r1][c0]);
        cout << sum << nl;
    }
}