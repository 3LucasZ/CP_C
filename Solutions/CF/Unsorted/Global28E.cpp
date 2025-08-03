#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n, m;
    cin >> n >> m;
    if (2 * n > m)
    {
        cout << "YES" << nl;
        int repeat = (m + 1) / 2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= repeat; j++)
            {
                cout << i << " ";
            }
            for (int j = repeat + 1; j <= m; j++)
            {
                int ans = i + j - repeat;
                if (ans > n)
                    ans -= n;
                cout << ans << " ";
            }
            cout << nl;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = repeat + 1; j <= m; j++)
            {
                int ans = i + j - repeat;
                if (ans > n)
                    ans -= n;
                cout << ans << " ";
            }
            for (int j = 1; j <= repeat; j++)
            {
                cout << i << " ";
            }
            cout << nl;
        }
    }
    else
    {
        cout << "NO" << nl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}