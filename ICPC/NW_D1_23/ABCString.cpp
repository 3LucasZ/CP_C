#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    string str; cin >> str;
    int n = str.size();

    vector<vector<int>> id(3, vector<int>(n/3+1));
    vector<int> cnt(3);
    for (int i=0;i<n;i++){
        int j = str[i]-'A';
        cnt[j]++;
        id[j][cnt[j]]=i;
    }
    for (int i=0;i<3;i++) {
        dbg(id[i]);
    }

    vector<int> presum(n+2);
    for (int i=1;i<=n/3;i++){
        int mn = min({id[0][i],id[1][i],id[2][i]});
        int mx = max({id[0][i],id[1][i],id[2][i]});
        presum[mn]++;
        presum[mx+1]--;
    }
    dbg(presum);

    for (int i=1;i<=n;i++){
        presum[i]+=presum[i-1];
    }
    dbg(presum);

    int ans = 0;
    for (int i=1;i<=n;i++) ans=max(ans, presum[i]);
    cout << ans << nl;
}