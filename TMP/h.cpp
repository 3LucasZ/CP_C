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
    vector<ld> p(n);
    vector<ld> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }
    dbg(n, p, w);
    ld tq = 0;
    for (int i = 0; i < n; i++)
    {
        tq += p[i] * w[i];
    }
    dbg(tq);
    int best_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[best_i] < w[i])
        {
            best_i = i;
        }
    }
    cout << fixed << setprecision(14) << abs(tq / w[best_i]) << nl;
}