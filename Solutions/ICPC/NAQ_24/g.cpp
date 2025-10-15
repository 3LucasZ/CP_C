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
    unordered_map<int, vector<int>> c_in_s;
    for (int i = 0; i < n; i++)
    {
        int s, c;
        cin >> s >> c;
        c_in_s[s].push_back(c);
    }

    ld ans = 0;
    for (const auto &entry : c_in_s)
    {
        vector<int> s = entry.second;
        dbg(s);
        sort(begin(s), end(s));
        int k = s.size();
        for (int i = 0; i < k / 2; i++)
        {
            ans += log(s[i]) - log(s[k - 1 - i]);
        }
    }
    cout << std::setprecision(15) << -ans << nl;
}