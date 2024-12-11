// SOL: sieve
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 2e6;

int main() {
    ll sum = 0;
    vector<bool> p(N+1, true);
    for (int i=2;i<=N;i++){
        if (p[i]) {
            sum += i;
            for (int j=2*i;j<=N;j+=i) p[j]=false;
        }
    }
    cout << sum << endl;
}