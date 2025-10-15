#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int pts(int e, int a)
{
    int ab = abs(e - a);
    if (ab <= 15)
        return 7;
    if (ab <= 23)
        return 6;
    if (ab <= 43)
        return 4;
    if (ab <= 102)
        return 2;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> e(n + 1);
    vector<int> a(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + pts(e[i + 1], a[j + 1]));
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << nl;
}