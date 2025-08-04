// https://codeforces.com/problemset/problem/2041/C

#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int n;
    cin >> n;
    vector<vector<vector<int>>> a(n,
                                  vector<vector<int>>(n,
                                                      vector<int>(n)));

    // depth
    for (int i = 0; i < n; i++)
    {
        // height
        for (int j = 0; j < n; j++)
        {
            // width
            for (int k = 0; k < n; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }

    vector<vector<int>> dp((1 << n), vector<int>((1 << n), 1e9));
    dp[0][0] = 0;
    for (int ybit = 0; ybit < (1 << n); ybit++)
    {
        int ybits = __builtin_popcount(ybit);
        for (int xbit = 0; xbit < (1 << n); xbit++)
        {
            int xbits = __builtin_popcount(xbit);
            if (xbits != ybits)
                continue;
            for (int y = 0; y < n; y++)
            {
                int ybit_ = ybit | (1 << y);
                if (ybit_ == ybit)
                    continue;
                for (int x = 0; x < n; x++)
                {
                    int xbit_ = xbit | (1 << x);
                    if (xbit_ == xbit)
                        continue;
                    // actual work LOL
                    dp[xbit_][ybit_] = min(dp[xbit_][ybit_], dp[xbit][ybit] + a[xbits][x][y]);
                }
            }
        }
    }
    int ans = dp[(1 << n) - 1][(1 << n) - 1];
    cout << ans << nl;
}