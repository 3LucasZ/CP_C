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
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    dbg(freq);

    vector<int> vis;
    ll ans = n * (n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            continue;

        ll col = 0;
        for (int j = 1; i * j <= n; j++)
        {
            col += freq[i * j];
        }
        ans -= col * (col - 1) / 2;
    }
    cout << ans << nl;
}

vector<bool> isPrime;
vector<ll> primes;
void sieve(int n)
{
    isPrime = vector<bool>(n + 1, true);
    isPrime[1] = false;
    for (int p = 2; p * p <= n; p++)
        if (isPrime[p])
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
    for (int p = 2; p <= n; p++)
        if (isPrime[p])
            primes.push_back(p);
}
int main()
{
    sieve(1e6);
    int t;
    cin >> t;
    while (t--)
        solve();
}