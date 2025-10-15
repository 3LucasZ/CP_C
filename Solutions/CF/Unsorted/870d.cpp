// https://codeforces.com/problemset/problem/1826/D
// 1700, 8-minute solve

#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> lmax(n);
    vector<int> rmax(n);
    for (int z = 0; z < 2; z++)
    {
        lmax[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(lmax[i - 1] - 1, a[i]);
        }
        swap(lmax, rmax);
        reverse(begin(a), end(a));
    }
    reverse(begin(rmax), end(rmax));
    int best = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        best = max(best, lmax[i - 1] + a[i] + rmax[i + 1]);
    }
    cout << best - 2 << nl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}