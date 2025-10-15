#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int x;
    for (int i = 0; i < 100; i++)
    {
        cin >> x;
    }
    int ans = x % 10;
    if (ans == 0)
        ans = 10;
    cout << ans << nl;
}