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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    int c3 = v[0];
    int a3 = v[n - 1];
    int a2b = v[n - 2];
    int a = a3 / 3;
    int b = a2b - 2 * a;
    int c = c3 / 3;
    cout << c << " " << b << " " << a << nl;
}