#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

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
    ll N, D, S;
    cin >> N >> D >> S;
    N /= S;
    D /= S;
    dbg(N, D);
    // dbg(999126190969 / S);
    // dbg(999126190969 / S * S);
    // 3 choices: N or N-1 or 2D
    sieve(1e6);
    ll T = 0;
    if (2 * D > N)
    {
        if (N - 2 <= D)
        {
            T = max(T, N - 1);
        }
        else
        {
            for (int i : primes)
            {
                if ((N - 1) % i == 0)
                {
                    if ((N - 1) - (N - 1) / i <= D)
                    {
                        T = max(T, N - 1);
                    }
                    break;
                }
            }
        }
        if (N - 1 <= D)
        {
            T = max(T, N);
        }
        for (int i : primes)
        {
            if (N % i == 0)
            {
                if (N - N / i <= D)
                {
                    T = max(T, N);
                }
                break;
            }
        }
        dbg(T);
    }
    else
    {
        T = 2 * D;
    }
    T = max(1LL, T);
    cout << T * S << nl;
}