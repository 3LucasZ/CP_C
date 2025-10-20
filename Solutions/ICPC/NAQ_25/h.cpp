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
    ld tq = 0;
    for (int i = 0; i < n; i++)
    {
        tq += p[i] * w[i];
    }
    cout << fixed << setprecision(15);

    // force torque to be > 0
    // all operations will be left shifts / merges
    if (tq < 0)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] *= -1;
        }
        reverse(begin(p), end(p));
        reverse(begin(w), end(w));
        tq *= -1;
    }
    dbg(p);
    dbg(w);

    // doubly linkedlist to store left and right person of each person
    vector<int> l(n);
    vector<int> r(n);
    iota(l.begin(), l.end(), -1);
    iota(r.begin(), r.end(), 1);

    // {weight, i, r[i]}
    priority_queue<tuple<ld, int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({w[i], i, r[i]});
    }
    ld ans = 0;
    // recursively move best person to the left to achieve 0 torque
    while (tq > 0)
    {
        auto [wi, i, ri] = pq.top();
        pq.pop();
        ld szi = r[i] - i;
        // skip outdated elements
        if (ri != r[i])
            continue;
        // left-most person is heaviest, move them left as much as you want, done
        if (i == 0)
        {
            ld space = tq / (wi * szi);
            ans += space * szi;
            break;
        }
        int j = l[i];
        ld szj = i - j;

        ld space = p[i] - p[j];
        // space is good enough, done
        if (space * szi * wi >= tq)
        {
            space = tq / (wi * szi);
            ans += space * szi;
            break;
        }
        // space is not good enough, merge i into j
        else
        {
            ans += space * szi;
            tq -= space * szi * wi;
            // calculate new weight
            w[j] = (w[i] * szi + w[j] * szj) / (szi + szj);
            // update DLL
            r[j] = r[i];
            if (r[i] < n)
                l[r[i]] = j;
            // insert new, merged cur
            pq.push({w[j], j, r[j]});
        }
    }
    cout << ans << nl;
}