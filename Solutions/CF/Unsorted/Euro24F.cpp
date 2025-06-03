#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    // input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> userPrefs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            userPrefs[i].push_back(x);
        }
    }
    userPrefs[0] = vector<int>(m, 1);
    dbg(userPrefs);

    // sort by size
    vector<int> ord(n + 1);
    for (int i = 0; i <= n; i++)
        ord[i] = i;
    sort(begin(ord) + 1, end(ord), [&](int a, int b)
         { return userPrefs[a].size() > userPrefs[b].size(); });
    dbg(ord);

    // which user owns which preferences
    vector<int> owner(m + 1);

    // top-down labelling
    for (int i = 1; i <= n; i++)
    {
        int user = ord[i];
        if (userPrefs[user].size() == 0)
            break;
        vector<pair<int, int>> pars;
        unordered_set<int> seen;
        for (int pref : userPrefs[user])
        {
            if (!seen.count(owner[pref]))
            {
                pars.push_back({userPrefs[owner[pref]].size(), owner[pref]});
                seen.insert(owner[pref]);
            }
            owner[pref] = user;
        }
        dbg(pars);
        dbg(owner);
        if (pars.size() > 1)
        {
            int par = min_element(begin(pars), end(pars))->second;
            cout << "YES" << nl;
            cout << par << " " << user << nl;
            return 0;
        }
    }
    cout << "NO" << nl;
}