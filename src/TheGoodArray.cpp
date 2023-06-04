#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef long long ll;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

const int MOD = 1000000007;
bool multi = true;
bool dbg = false;

void solve(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    
    for (int i=0;i<2;i++){
        int cnt = 0;
        for (int j=0;j<N;j++){
            if (A[j]==1) cnt++;
            int ceil = (j+1+K-1)/K;
            if (cnt<ceil){
                cnt++;
                A[j]=1;
            }
        };
        reverse(begin(A),end(A));
    }
    int ans = 0;
    for (int i=0;i<N;i++){
        if (A[i]==1) ans++;
    }
    if (dbg){
        for (int i=0;i<N;i++) cout << A[i] << " ";
        cout << endl;
    }
    cout << ans << endl;
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for (int i=0;i<T;i++) solve();
    return 0;
}