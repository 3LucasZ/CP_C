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
    vector<int> next(n + 1);
    vector<int> in(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> next[i];
        in[next[i]]++;
    }

    // recursively remove all nodes with in[u] = 0
    queue<int> q;
    vector<int> color(n + 1); // 1 => black, 2 => white
    bool bad = false;
    for (int u = 1; u <= n; u++)
    {
        if (in[u] == 0)
            q.push(u);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (color[u] == 2)
        {
            continue;
        }
        color[u] = 1;

        int v = next[u];
        // if (color[v] == 1)
        // {
        //     bad = true;
        // }
        if (color[v] == 0)
        {
            color[v] = 2;
            in[next[v]]--;
            if (in[next[v]] == 0)
                q.push(next[v]);
        }
    }
    dbg(color);
    // handle cycles
    for (int u = 1; u <= n; u++)
    {
        if (color[u] != 0)
            continue;
        int sz = 1;
        int cur = u;
        color[cur] = 1;
        while (next[cur] != u)
        {
            color[next[cur]] = 3 - color[cur];
            cur = next[cur];
            sz++;
        }
        if (sz % 2 == 1)
            bad = true;
    }
    dbg(color);
    dbg(bad);

    // return answer
    if (bad)
    {
        cout << -1 << nl;
        return 0;
    }
    // iterate over uncircled nodes (black) in order
    vector<int> ret;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            ret.push_back(next[i]);
        }
    }
    cout << ret.size() << nl;
    for (int x : ret)
    {
        cout << x << " ";
    }
    cout << nl;
}