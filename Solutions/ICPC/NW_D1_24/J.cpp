#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c;
    int m2 = m;
    for (int i=0;i<m2;i++){
        int ci; cin >> ci;
        if (ci == n) m--;
        else c.push_back(ci);
    }
    sort(begin(c), end(c));

    int ans = 1;
    for (int j=m-1;j>=1;j--){
        int gap = n-c[j];
        if (gap+1<c[0]){
            c[0]-=(gap+1);
            ans++;
        }
    }
    cout << ans << endl;
}