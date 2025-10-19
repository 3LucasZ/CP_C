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
    vector<int> cnt(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> w[i];
    }
    ld tq = 0;
    for (int i = 0; i < n; i++)
    {
        tq += p[i] * w[i];
    }
    if (tq > 0)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] *= -1;
            reverse(begin(p), end(p));
            reverse(begin(w), end(w));
        }
        tq *= -1;
    }
    p.push_back(1e20);
    dbg(p);
    dbg(w);
    dbg(cnt);

    auto cmp = [&](int a, int b)
    { return w[a] / cnt[a] < w[b] / cnt[b]; };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++)
    {
        pq.push(i);
    }
    ld ans = 0;
    cout << fixed << setprecision(15);
    while (tq < 0)
    {
        int cur = pq.top();
        dbg(cur);
        int nxt = cur + 1;
        ld space = p[nxt] - p[cur];
        // space is good enough, done
        if (space * w[cur] >= -tq)
        {
            // update ans, tq
            ans += -tq / w[cur] * cnt[cur];
            tq = 0;
        }
        // space is not good enough, take entire thing and merge
        else
        {
            // update ans, tq
            ans += space * cnt[cur];
            tq += w[cur] * space;
            // update elements
            cnt[nxt] += 1;
            w[nxt] += w[cur];
            pq.pop();
        }
    }
    cout << ans << nl;
}