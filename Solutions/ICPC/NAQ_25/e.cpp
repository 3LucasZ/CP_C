#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int tot1 = 0;
    int tot2 = 0;
    for (int i = 0; i < 10; i++)
    {
        vector<vector<ll>> d(2);
        for (int k = 0; k < 2; k++)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                ll x, y;
                cin >> x >> y;
                ll dist = (x - 144) * (x - 144) + (y - 84) * (y - 84);
                d[k].push_back(dist);
            }
        }
        // dbg(d);

        // update score
        vector<int> score(2);
        for (int k = 0; k < 2; k++)
        {
            for (ll dist : d[k])
            {
                bool ok = true;
                for (ll dist2 : d[1 - k])
                {
                    if (dist2 < dist)
                        ok = false;
                }
                if (ok)
                    score[k] += 1;
            }
        }
        tot1 += score[0];
        tot2 += score[1];
    }

    // ret
    cout << tot1 << " " << tot2 << nl;
}