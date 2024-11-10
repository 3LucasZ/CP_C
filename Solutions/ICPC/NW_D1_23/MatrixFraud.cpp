#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int R, C; 
vector<vector<int>> A;
vector<vector<int>> sum;

int change(int i, int s, int t) {
    int a = sum[i][s-1];
    int b = (t-s+1)-(sum[i][t]-sum[i][s-1]);
    int c = sum[i][C]-sum[i][t];
    return a + b + c;
}
int main() {
    cin >> R >> C;
    if (R<C){ //transpose
        A.resize(C+1, vector<int>(R+1));
        for (int r=1;r<=R;r++){
            string str; cin >> str;
            for (int c=1;c<=C;c++){
                A[c][r] = str[c-1]-'0';
            }
        }
        swap(R,C);
    } else { // normal
        A.resize(R+1, vector<int>(C+1));
        for (int r=1;r<=R;r++){
            string str; cin >> str;
            for (int c=1;c<=C;c++){
                A[r][c] = str[c-1]-'0';
            }
        }
    }

    sum.resize(R+1, vector<int>(C+1));
    for (int r=1;r<=R;r++){
        for (int c=1;c<=C;c++){
            sum[r][c] = sum[r][c-1] + A[r][c];
        }
    }

     
    vector<vector<vector<int>>> dp(R+1, vector<vector<int>>(C+2, vector<int>(C+2, R*C)));
    for (int t=1;t<=C;t++){
        int s = 1;
        dp[1][s][t] = change(1, s, t);
        for (int s=1;s<=t;s++) dp[1][t+1][t] = min(dp[1][t+1][t], dp[1][s][t]);
    }

    for (int i=2;i<=R;i++){
        for (int t=1;t<=C;t++){
            int stink = R*C;
            for (int s=1;s<=t;s++){
                stink = min(stink, dp[i-1][s][t]);
                dp[i-1][s][t] = min(dp[i-1][s][t-1], stink);
                dp[i][s][t] = dp[i-1][s][t] + change(i, s, t);
            }
            for (int s=1;s<=t;s++) dp[i][t+1][t] = min(dp[i][t+1][t], dp[i][s][t]);
        }
    }

    int ans = R*C;
    for (int s=1;s<=C;s++){
        int t = C;
        ans = min(ans, dp[R][s][t]);
    }
    cout << ans << nl;
}