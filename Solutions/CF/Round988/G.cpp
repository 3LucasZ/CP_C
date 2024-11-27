#include<bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;

ll MOD = 998244353;
vector<bool> isPrime;
vector<int> primes;
void sieve(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
    for (int p=2;p<=n;p++) if (isPrime[p]) primes.push_back(p);
}
vector<int> primeFactorize(int val){
    vector<int> ret;
    for (int pi=0;primes[pi]*primes[pi]<=val;pi++){
        int p = primes[pi];
        if (val%p==0){
            ret.push_back(p);
        }
        while (val%p==0) val/=p;
    }
    if (val>1) ret.push_back(val);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];


    //solve
    vector<ll> dp(1e6+1);
    for (int i=1;i<=n;i++){
        //setup
        ll ans = 0;
        if (i==1) ans = 1;
        vector<int> decomp = primeFactorize(a[i]);
        // dbg(a[i],decomp);
        
        //ans
        int mx = decomp.size();
        vector<int> prods;
        for (int ss=0;ss<(1<<mx);ss++){
            vector<int> subset;
            int prod = 1;
            int mult = -1;
            for (int j=0;j<mx;j++){
                if ((1<<j)&ss){
                    mult *= -1;
                    prod*=decomp[j];
                }
            }
            prods.push_back(prod);
            // dbg(subset, prod);
            ans += mult * dp[prod];
        }
        ans%=MOD;ans+=MOD;ans%=MOD;
        // dbg(ans);

        //upd
        // dbg(prods);
        for (int prod : prods){
            if (prod!=1) {
                dp[prod] = (dp[prod]+ans)%MOD;
            }
        }
        if (i==n){
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    // auto start = chrono::high_resolution_clock::now();
    sieve(1e6);
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << duration.count() << endl;
    // dbg(primeFactorize(2*2*3*3*5*5*7*7));
    solve();
    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cout << duration.count() << endl;
}