#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ld> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    dbg(n, k, a);

    ld w_sum = 0;
    ld w_sum2 = 0;
    ld best = LDBL_MAX;
    for (int i = 0; i < n; i++)
    {
        w_sum += a[i];
        w_sum2 += a[i] * a[i];
        if (i >= k - 1)
        {
            ld w_avg = w_sum / k;
            ld next = k * w_avg * w_avg - 2 * w_avg * w_sum + w_sum2;
            dbg(w_sum, w_sum2, w_avg, next);
            best = min(best, next);
            w_sum -= a[i - (k - 1)];
            w_sum2 -= a[i - (k - 1)] * a[i - (k - 1)];
        }
    }
    cout << fixed << setprecision(7) << best << nl;
}