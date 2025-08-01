#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < s.length(); i++)
    {
        cnt[s[i] - 'A']++;
    }
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << (char)('A' + i);
        }
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