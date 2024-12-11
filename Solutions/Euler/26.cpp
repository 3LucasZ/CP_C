#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n = 1000;

int length(int x) {
    vector<int> vis(10*x);
    int cur = 1;
    for (int i=1;i<=10*x;i++){
        if (vis[cur]) return i-vis[cur];
        vis[cur] = i;
        cur = (cur%x)*10;
    }
}
int main() {
    int ans = 1;
    for (int i=1;i<=n;i++){
        if (length(i) > length(ans)) ans = i;
    }
    cout << ans << endl;
}