#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n%2==0){
        for (int i=0;i<n/2;i++){
            cout << i+1 << " " << i+1 << " ";
        }
        cout << endl;
    }
    else {
        if (n<27) {
            cout << -1 << endl;
        } else {
            int laid = 2;
            for (int i=1;i<=n;i++){
                if (i==1 || i==10 || i==26) {
                    cout << 1000000 << " ";
                } else if (i==23 || i==27) {
                    cout << 1000000-1 << " ";
                }
                else {
                    cout << laid/2 << " ";
                    laid++;
                }
            }
            cout << endl;
        }
    }
}
int main() {
    int t; cin >> t; while (t--) solve();
}