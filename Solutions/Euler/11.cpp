#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

int n = 20;
vector<int> dr={0,1,1,1};
vector<int> dc={1,0,1,-1};
bool ok(int r, int c){
    return r>=0 && r<n && c>=0 && c<n;
}
int main() {
    vector<vector<int>> a(n, vector<int>(n));
    for (int r=0;r<n;r++){
        for (int c=0;c<n;c++){
            string s; cin >> s;
            a[r][c] = (s[0]-'0')*10+(s[1]-'0');
            cout << a[r][c] << " ";
        }
        cout << endl;
    }

    int ans = 0;
    for (int r=0;r<n;r++){
        for (int c=0;c<n;c++){
            for (int i=0;i<4;i++){ // pick direction
                int prod=1;
                int rr=r;
                int cc=c;
                for (int j=0;j<4;j++){ // collect direction
                    if (ok(rr,cc)) prod*=a[rr][cc];
                    rr+=dr[i];
                    cc+=dc[i];
                }
                ans = max(ans,prod);
            }
        }
    }
    cout << ans << endl;
}