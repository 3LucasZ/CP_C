#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    // input
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<int> ai(n + 1);
    vector<vector<int>> ais(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ai[a[i]] = i;
        ais[a[i]].push_back(i);
    }
    vector<int> bi(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bi[b[i]] = i;
    }
    vector<int> to(n + 1);
    for (int i = 1; i <= n; i++)
    {
        to[i] = ai[b[i]];
        if (a[to[i]] < a[i])
        {
            cout << "-1" << endl;
            return;
        }
    }

    // answer
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j : ais[i])
        {
            cout << j << " " << to[j] << endl;
        }
    }
}
int main()
{

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case: #" << i << ": ";
        solve();
    }
}