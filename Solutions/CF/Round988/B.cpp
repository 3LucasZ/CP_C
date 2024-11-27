#include<bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> cnt(k+1);
    for (int i=0;i<k;i++){
        int x; cin >> x;
        cnt[x]++;
    }
    // for (int i=0;i<=k;i++) cout << cnt[i] << " ";
    // cout << endl;
    
    for (int i=1;i<=k-2;i++){
        if ((k-2)%i==0) {
            int j = (k-2)/i;
            if (i==j){
                if (cnt[i]>=2) {
                    cout << i << " " << i << endl;
                }
            }
            else if (cnt[i] && cnt[j]) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}
int main() {
    int t; cin >> t; while (t--) solve();
}