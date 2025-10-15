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
    vector<int> cnt(51);
    for (int i = 0; i < 5 * 10 * n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool ok = false;
    for (int i = 1; i <= 50; i++)
    {
        if (cnt[i] > 2 * n)
        {
            ok = true;
            cout << i << " ";
        }
    }
    if (ok)
    {
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}