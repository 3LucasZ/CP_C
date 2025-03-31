#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

vector<bool> isPrime;
void sieve(int n){
    isPrime = vector<bool>(n+1,true); isPrime[1]=false;
    for (int p=2;p*p<=n;p++) if (isPrime[p]) for (int i=p*p;i<=n;i+=p) isPrime[i]=false;
}
int main() {
    sieve(100000);
    int t; cin >> t; while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;i++){
            if (isPrime[i] && i>=n/3-1) {
                //i is the epic prime! let's return
                vector<bool> vis(n+1);
                cout << i << " ";
                vis[i] = true;
                for (int j=1;j<=n;j++){
                    if (i-j < 1 || i+j > n) break;
                    cout << i-j << " ";
                    cout << i+j << " ";
                    vis[i-j] = true;
                    vis[i+j] = true;
                }
                for (int j=1;j<=n;j++){
                    if (!vis[j]) cout << j << " ";
                }
                cout << nl;
                break;
            }
        }
    }
}