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
    vector<ld> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ld> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        s[i];
    }
    sort(begin(s), end(s));
    reverse(begin(s), end(s));
    dbg(n, a, s);
    ld best_avg_score = 0;
    ld score = 0;
    for (int i = 0; i < n; i++)
    {
        score += s[i];
        ld avg_score = (score + a[i]) / (i + 1);
        best_avg_score = max(best_avg_score, avg_score);
    }

    cout << fixed << setprecision(7) << best_avg_score << nl;
}