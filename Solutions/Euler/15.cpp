#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n = 20;


int main() {
    vector<vector<ll>> chs(2*n+1, vector<ll>(2*n+1));
    chs[0][0] = 1;
    for (int i=1;i<=2*n;i++){
        chs[i][0] = 1;
        for (int j=1;j<=2*n;j++){
            chs[i][j]=chs[i-1][j]+chs[i-1][j-1];
        }
    }
    cout << chs[2*n][n] << endl;
}