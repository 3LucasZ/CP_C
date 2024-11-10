#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <iterator>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

template<class T> using pq = priority_queue<T>;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const int MOD = 1000000007;
bool multi = true;
bool dbg = false;

const int MAXN = 1000;
int A[MAXN];

void solve(){
    int N; cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i];
    A[0]=0; A[N+1]=INT_MAX/2;
    if (dbg){
        for (int i=0;i<=N+1;i++) cout << A[i] << " ";
        cout << endl;
    }

    int dp[2][N+1][N+2];
    //fw/bw
    for (int t=0;t<2;t++){
        reverse(begin(A),begin(A)+2+N);
        //base
        for (int i=0;i<=N;i++) for (int j=0;j<=N+1;j++) dp[t][i][j]=INT_MAX/2;
        dp[t][0][1]=N;
        //trans
        for (int i=0;i<N;i++){
            for (int j=0;j<=N;j++){
                if ((t==1 && A[i+1]>A[i]) || (t==0 && A[i+1]<A[i])) dp[t][i+1][j]=min(dp[t][i+1][j],dp[t][i][j]-1);
                for (int i2=i+2;i2<=N;i2++){
                    if ((t==1 && A[i2]>A[i]) || (t==0 && A[i2]<A[i])) dp[t][i2][j+1]=min(dp[t][i2][j+1],dp[t][i][j]-1);
                }
            }
        }
        for (int j=0;j<=N;j++){
            dp[t][N][j] = min(dp[t][N][j],dp[t][N][j+1]);
        }
    }
    if (dbg){
    for (int t=0;t<2;t++) for (int i=0;i<=N;i++) for (int j=0;j<=N;j++) if (dp[t][i][j]<N+10) 
        cout << "YUCK["<<t<<"]["<<i<<"]["<<j<<"] = " << dp[t][i][j] << endl;
    }
    int baseline = INT_MAX/2;
    for (int j=1;j<=N;j++){
        int ans = baseline;
        for (int t=0;t<2;t++) for (int i=0;i<=N;i++){
            ans=min(ans,dp[t][i][j]);
        }
        baseline = min(baseline,ans);
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) {
        if (dbg) cout << "SOLVING: " << i+1 << endl;
        solve();
    }
    return 0;
}