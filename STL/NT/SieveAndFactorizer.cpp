#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()








//figure out if a number is prime or not
vector<bool> isPrime;
vector<ll> primes;
void sieve(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}

//figure out the leastPrime divisor of a number
//leastPrime[i] = 0 means i is prime
vector<int> leastPrime;
// vector<ll> primes;
void sieve2(int n){
    leastPrime.resize(n+1,0); leastPrime[1]=1;
    for (int p=2;p*p<=n;p++) if (leastPrime[p]==0) for (int i=p*p;i<=n;i+=p) if (leastPrime[i]==0) leastPrime[i]=p;
    for (int p=2;p<=n;p++) if (leastPrime[p]==0) primes.push_back(p);
}

//prime factorize a number
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

int main() {
    sieve(1e5);
    dbg(primes.size()); // should be 9592
    primes.clear();
    sieve(1e6);
    dbg(primes.size()); // should be 78498
    
    dbg(primeFactorize(178));
    dbg(primeFactorize(6238945));
    return 0;
}