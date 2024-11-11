#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

const int MAX = 4e5;

vector<bool> isPrime;
vector<ll> primes;
vector<ll> dp(MAX, 0);

void sieve(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}

vector<ll> primeFactorize(ll val){
    vector<ll> ret;
    for (int pi=0;primes[pi]*primes[pi]<=val;pi++){
        ll p = primes[pi];
        while (val%p==0){
            ret.push_back(p);
            val/=p;
        }
    }
    if (val>1) ret.push_back(val);
    return ret;
}

void solve() {
    int n; cin >> n;
    int p = 0; int pr;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (isPrime[a[i]]) {
            p++;
            pr = a[i];
        }
    }
    dbg(n, a);
    dbg(p, pr);

    if (p > 1) {
        cout << -1 << nl;
        return;
    }
    else if (p == 1) {
        bool ok = true;
        for (int x : a){
            if (dp[x]<pr) ok = false;
        }
        if (ok) {
            cout << pr << nl;
        } else {
            cout << -1 << nl;
        }
    } else {
        cout << 2 << nl;
        return;
    }
}


int main() {
    sieve(MAX);
    for (int i=2;i<=MAX;i++){
        if (isPrime[i]) dp[i] = i;
        for (int p : primeFactorize(i)) {
            if (i+p <= MAX) dp[i+p] = max(dp[i+p], dp[i]);
        }
    }
    int t; cin >> t;
    while (t--) solve();
}