#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

vector<bool> isPrime;
vector<ll> primes;
void sieve(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}

int main() {
    // precompute primes/isprime up to 1e6
    // sieve(1e3);
    // dbg(primes, isPrime);
    sieve(1e6);

    // precompute is prime^2
    unordered_map<ll, ll> isPrime2;
    for (ll p : primes) isPrime2[p*p]=p;

    unordered_map<ll, ll> add;
    unordered_map<ll, ll> sub;

    ll n; cin >> n;
    for (int i=0;i<n;i++){
        ll a; cin >> a;
        dbg(a);
        // for each number grab ps array
        vector<ll> ps;
        for (ll p : primes) {
            if (a % (p*p) == 0) {
                ps.push_back(p);
            }
            while (a % p == 0) a /= p;
            if (p*p * p > a) {
                break;
            }
        }
        if (isPrime2[a]) ps.push_back(isPrime2[a]);
        dbg(ps);
        // for each combo in ps array
        for (int i=0;i<(1<<ps.size());i++){
            ll combo = 1;
            int used = 0;
            for (int j=0;j<ps.size();j++){
                if (i&(1<<j)){
                    combo *= ps[j];
                    used++;
                }
            }
            // dbg(combo);
            if (used%2==0) {
                sub[combo]++;
            } else {
                add[combo]++;
            }
        }
    }

    // maths
    dbg(add);
    dbg(sub);
    ll ans = 0;
    for (auto pair : sub) {
        ans += (pair.second*(pair.second-1)/2);
    }
    for (auto pair : add) {
        ans -= (pair.second*(pair.second-1)/2);
    }
    cout << ans << nl;
}