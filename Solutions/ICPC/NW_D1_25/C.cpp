#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> l(n);
    vector<int> r(n);
    for (int z = 0; z < 2; z++)
    {
        vector<int> c_idx(n + 1, -1);
        vector<int> pre_idx(n);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            // update pre_idx, c_idx for i
            pre_idx[i] = c_idx[a[i]];
            c_idx[a[i]] = i;
            // force i is valid rhs of interval
            if (pre_idx[i] == -1)
                continue;
            // force i to not contain another interval
            if (!stk.empty() && pre_idx[stk.top()] > pre_idx[i])
                continue;
            // maintain stack monotonicity
            while (!stk.empty())
            {
                int cur = stk.top();
                if (z == 0)
                {
                    if (cur - pre_idx[cur] < i - pre_idx[i])
                    {
                        break;
                    }
                }
                // ---AVOID DOUBLE COUNTING INSANELY ELEGANT MOVE!!!---
                else
                {
                    if (cur - pre_idx[cur] <= i - pre_idx[i])
                    {
                        break;
                    }
                }
                stk.pop();
            }
            // update l for i
            int l_idx;
            if (!stk.empty())
                l_idx = pre_idx[stk.top()] + 1;
            else
                l_idx = 0;
            l[i] = pre_idx[i] - l_idx + 1;
            // update stack
            stk.push(i);
        }
        dbg(a);
        dbg(pre_idx);
        dbg(l);
        swap(l, r);
        reverse(begin(a), end(a));
    }

    long long ans = 0;
    vector<int> c_idx(n + 1, -1);
    vector<int> pre_idx(n);
    for (int i = 0; i < n; i++)
    {
        // update pre_idx, c_idx for i
        pre_idx[i] = c_idx[a[i]];
        c_idx[a[i]] = i;
        // update ans for valid intervals
        if (pre_idx[i] != -1)
            ans += (long long)l[i] * r[n - 1 - pre_idx[i]] * (i - pre_idx[i]);
    }
    cout << ans << endl;
}