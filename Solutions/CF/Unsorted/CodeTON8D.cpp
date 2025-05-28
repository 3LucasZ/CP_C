#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            cin >> a[l][r];
        }
    }
    dbg(n, k, a);

    // dp
    vector<priority_queue<int>> dp(n + 1);
    dp[0].push(0);
    dp[1].push(0);
    dp[1].push(a[1][1]);
    dbg(dp[0], dp[1]);
    for (int r = 2; r <= n; r++)
    {
        // create initial heap
        priority_queue<pair<int, int>> heap;
        vector<pair<int, int>> removed;
        for (int i = 0; i <= r - 1; i++)
        {
            pair<int, int> top = {dp[i].top(), i};
            dp[i].pop();
            removed.push_back({top.first, top.second});
            if (i == r - 1)
                heap.push({top.first, top.second});
            else
                heap.push({top.first + a[i + 2][r], top.second});
        }
        heap.push({a[1][r], -1});
        // get top element from heap and update it (k times)
        for (int _ = 0; _ < k && !heap.empty(); _++)
        {
            pair<int, int> top = heap.top();
            heap.pop();
            dp[r].push(top.first);
            int i = top.second;
            if (i != -1 && !dp[i].empty())
            {
                pair<int, int> newTop = {dp[i].top(), i};
                dp[i].pop();
                removed.push_back({newTop.first, newTop.second});
                if (i == r - 1)
                    heap.push({newTop.first, newTop.second});
                else
                    heap.push({newTop.first + a[i + 2][r], newTop.second});
            }
        }
        // restore all the heaps
        for (pair<int, int> top : removed)
        {
            dp[top.second].push(top.first);
        }
        dbg(dp[r]);
    }

    // ret
    for (int _ = 0; _ < k; _++)
    {
        cout << dp[n].top() << " ";
        dp[n].pop();
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