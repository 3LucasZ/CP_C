#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_set<int> uq;
    for (int i = 0; i < n; i++)
    {
        uq.insert(a[i]);
    }
    cout << min(k, (int)uq.size()) << nl;
}