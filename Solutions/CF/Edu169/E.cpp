#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

//leastPrime[i] = 0 means i is prime
vector<int> leastPrime;
vector<int> primes;
// NOT PERFECT: i.e. nim(2)=0 NOT 1 and nim(1)=1 (weird)
map<int, int> primeToNim;
void sieve(int n){
    leastPrime.resize(n+1,0); leastPrime[1]=1;
    for (int p=2;p*p<=n;p++) if (leastPrime[p]==0) for (int i=p*p;i<=n;i+=p) if (leastPrime[i]==0) leastPrime[i]=p;
    for (int p=2;p<=n;p++) if (leastPrime[p]==0) {
        primes.push_back(p);
        primeToNim[p]=primes.size();
    }
    primeToNim[1] = 1;
    primeToNim[2] = 0;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        int lp = leastPrime[x];
        if (lp == 0) lp = x;
        int nim = primeToNim[lp];
        sum ^= nim;
    }
    if (sum==0) cout << "Bob" << nl;
    else cout << "Alice" << nl;
}

int main(){
    sieve(1e7);
    int t; cin >> t; while (t--) solve();
}