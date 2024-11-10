#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
const ld inf = 1e18;
#define all(x) (x).begin(), (x).end();

int N;
pair<ld, ld> home;
vector<pair<ld, ld>> x;
vector<ld> dp;

ld DDD(pair<ld,ld> &a, pair<ld,ld> &b){
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

int main() {
    cin >> home.first >> home.second;
    cin >> N;
    x.resize(N);
    for (int i=0;i<N;i++){
        cin >> x[i].first >> x[i].second;
    }
    dbg(x);

    dp.resize(1<<N, inf); 
    dp[0] = 0;
    for (int i=0;i<N;i++){
        dp[1<<i] = 2*DDD(home, x[i]);
    }
    for (int set=0;set<(1<<N);set++) {
        dbg(bitset<4>(set));
        for (int i=0;i<N;i++){
            if ((set&(1<<i)) == 0) {
                for (int j=i+1;j<N;j++){
                    if ((set&(1<<j)) == 0){
                        int nxt = (set|(1<<i)|(1<<j));
                        dbg(bitset<4>(nxt));
                        dp[nxt] = min(dp[nxt], dp[set] + DDD(x[i],x[j]) + DDD(home,x[i]) + DDD(home,x[j]));
                    }
                }
            }
        }
    }
    ld worst = 0;
    for (int i=0;i<N;i++) worst = max(worst, DDD(x[i],home));
    dbg(dp);

    
    cout << setprecision(10) << dp[(1<<N)-1]-worst << nl;
}