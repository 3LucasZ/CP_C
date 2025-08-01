#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    dbg(b);
    vector<int> x(q);
    vector<int> y(q);
    vector<int> z(q);
    for (int i = 0; i < q; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
        z[i]--;
    }

    // perform operations backward
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = b[i];
    }
    for (int i = q - 1; i >= 0; i--)
    {
        l[x[i]] = max(l[x[i]], l[z[i]]);
        l[y[i]] = max(l[y[i]], l[z[i]]);
        if (z[i] != x[i] && z[i] != y[i])
            l[z[i]] = 0;
    }
    dbg(l);

    // perform operations forward
    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = l[i];
    }
    for (int i = 0; i < q; i++)
    {
        c[z[i]] = min(c[x[i]], c[y[i]]);
    }
    dbg(c);

    // check
    for (int i = 0; i < n; i++)
    {
        if (c[i] != b[i])
        {
            cout << -1 << nl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << l[i] << " ";
    }
    cout << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}