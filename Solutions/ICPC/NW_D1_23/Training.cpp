#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int N; int S;
vector<pair<int,int>> a;
int main() {
    cin >> N >> S;
    a.resize(N+1);
    for (int i=1;i<=N;i++){
        cin >> a[i].first;
        cin >> a[i].second;
    }
    dbg(N,S,a);

    vector<int> dp(N+1); dp[0] = S;
    for (int i=1;i<=N;i++){
        dp[i]=dp[i-1];
        if (a[i].first<=dp[i] && dp[i] <=a[i].second) dp[i]++;
    }

    cout << dp[N] << nl;
}