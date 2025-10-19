#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

// -- Sieve O(n) --
// figure out if a number is prime or not
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

// -- Modified Sieve O(n) --
// figure out the leastPrime divisor of a number
// leastPrime[i] = 0 means i is prime
vector<int> leastPrime;
void sieve2(int n)
{
    leastPrime.resize(n + 1, 0);
    leastPrime[1] = 1;
    for (int p = 2; p * p <= n; p++)
        if (leastPrime[p] == 0)
            for (int i = p * p; i <= n; i += p)
                if (leastPrime[i] == 0)
                    leastPrime[i] = p;
    for (int p = 2; p <= n; p++)
        if (leastPrime[p] == 0)
            primes.push_back(p);
}

// -- Factorizer O(sqrt(n/logn)) --
// prime factorize x as sorted vector
vector<ll> primeFactorize(ll x)
{
    vector<ll> ret;
    for (int pi = 0; primes[pi] * primes[pi] <= x; pi++)
    {
        ll p = primes[pi];
        while (x % p == 0)
        {
            ret.push_back(p);
            x /= p;
        }
    }
    if (x > 1)
        ret.push_back(x);
    return ret;
}

// -- Divisor generator O(n^1/3) --
// loop over all divisors of x in decomposition form
void _divGen(int div, unordered_map<int, int> divf, int l, vector<ll> &xf)
{
    if (l == xf.size())
    {
        // custom collector function
        dbg(divf);
        return;
    }
    // recurse
    int r = l + 1;
    while (r < xf.size() && xf[r] == xf[l])
        r++;
    for (int j = 0; j <= (r - l); j++)
    {
        unordered_map<int, int> divf2 = divf;
        divf2[xf[l]] = j;
        _divGen(div, divf2, r, xf);
        div *= xf[l];
    }
}
void divGen(ll x)
{
    vector<ll> xf = primeFactorize(x);
    unordered_map<int, int> divf;
    _divGen(1, divf, 0, xf);
}

int main()
{
    sieve(1e5);
    dbg(primes.size()); // 9592
    primes.clear();
    sieve(1e6);
    dbg(primes.size());           // 78498
    dbg(primeFactorize(6238945)); // {5, 73, 17093}
    divGen(2 * 2 * 3 * 3 * 4 * 4);
    return 0;
}