#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n<5){
        cout << -1 << endl;
        return;
    }
    vector<int> ret(n+1);
    for (int i=1;i<=n;i++){
        int x = (n+1)/2;
        if (i%2==0) ret[x+i/2] = i;
        else ret[i/2+1] = i;
    }

    int a = (n+1)/2;
    swap(ret[a],ret[3]);
    int b = (n+1)/2+1;
    swap(ret[b],ret[b+1]);

    for (int i=1;i<=n;i++){
        cout << ret[i] << " ";
    }
    cout << endl;

}
int main() {
    int t; cin >> t; while (t--) solve();
}