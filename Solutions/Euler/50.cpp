#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n = 100;

int main() {
    vector<int> primes;
    vector<bool> isPrime(n+1, true);
    for (int i=2;i<=n;i++){
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=2*i;j<=n;j+=i) isPrime[j]=false;
        }
    }
    for (int p : primes) cout << p << " ";
    cout << endl;
    
    vector<int> dp(n+1);
    for (int p1 : primes) {
        for (int p2 : primes) {
            if (p2 > p1) break;
            dp[p1]=max(dp[p1], dp[p1-p2]+dp[p2]);
        }
    }
    for (int p : primes) cout << dp[p] << " ";
    cout << endl;

    int ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}