#include <iostream>
using namespace std;
typedef long long ll;

/*
INFO:
Cfg: N/A
Stress tested: NO
Site: N/A
*/

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
    cout << gcd(1000, 250) << endl;
    ll a = 47L * 2500 * 6956343;
    ll b = 47L * 1000;
    cout << gcd(a, b) << endl;
}