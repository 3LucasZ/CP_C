#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

//TODO: switch off when not testing!
bool multi = false; 

int m, n;

// number of elements in "a" STRICTLY LESS THAN key
int orderOf(vector<int> a, int key){
    int lo=-1; int hi=a.size()-1;
    while (lo<hi){
        int mid = (lo+hi+1)/2;
        if (a[mid] < key) lo=mid;
        else hi=mid-1;
    }
    return lo+1;
}

void solve() {
    cin >> m >> n;
    vector<int> records;
    for (int i=0;i<m;i++){
        int x; cin >> x;
        records.push_back(x);
    }
    dbg(m,n,records);

    //0 -> point, 1 -> checkI, 2 -> checkS
    vector<vector<int>> metaCheckI(n+1);
    vector<vector<int>> metaCheckS(n+1);
    int t = 0;
    for (int i=0;i<m;i++){
        if (records[i]>0){
            metaCheckI[t].push_back(records[i]);
        } else if (records[i]<0){
            metaCheckS[t].push_back(-records[i]);
        } else {
            t++;
        }
    }
    for (int i=0;i<=n;i++){
        sort(metaCheckI[i].begin(), metaCheckI[i].end());
        sort(metaCheckS[i].begin(), metaCheckS[i].end());
        dbg(metaCheckI[i], metaCheckS[i]);
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    dp[0][0] = 0;
    for (int i=1;i<=n;i++){
        int points = i+1;
        for (int intel=0;intel<=points;intel++){
            int strength = points-intel;
            dp[i][intel] = max({0, dp[i-1][intel-1], dp[i-1][intel]});
            dp[i][intel] = dp[i-1][intel] + orderOf(metaCheckI[i],intel+1) + orderOf(metaCheckS[i],strength+1);
        }
    }

    int ans = 0;
    for (int i=0;i<=n;i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << nl;
}

int main() {
    int q; 
    if (multi) cin >> q;
    else q = 1;
    for (int i=0;i<q;i++) solve();
}