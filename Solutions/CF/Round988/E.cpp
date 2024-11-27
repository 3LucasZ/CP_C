#include<bits/stdc++.h>
using namespace std;

int query(int l, int r){
    cout << "?" << " " << l << " " << r << endl;
    int ans; cin >> ans;
    return ans;
}
void solve() {
    int n;
    cin >> n;
    
    vector<int> ret(n+1);
    // part 1
    int i;
    int cnt;
    bool impossible = true;
    for (i=2;i<=n;i++){
        cnt = query(1,i);
        // [i-1,i] is the first [0,1] point ever!
        if (cnt > 0) {
            for (int j=1;j<i-cnt;j++){
                ret[j]=1;
            }
            ret[i]=1;
            impossible = false;
            break;
        }
    }
    if (impossible) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    //part 2;
    for (int j=i+1;j<=n;j++){
        int cur = query(1,j);
        if (cur > cnt) {
            ret[j] = 1;
            cnt = cur;
        }
    }

    // ret
    cout << "! ";
    for (int i=1;i<=n;i++){
        cout << ret[i];
    }
    cout << endl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}