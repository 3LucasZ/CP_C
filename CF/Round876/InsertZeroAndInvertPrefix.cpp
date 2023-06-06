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

#define f first
#define s second

const int MOD = 1000000007;
bool multi = true;
bool dbg = false;

void solve(){
    int N;
    cin >> N;
    vi A(N);
    
    for (int i=0;i<N;i++) cin>>A[i];
    if (dbg){
        for (int i=0;i<N;i++){
            cout << A[i] <<  ", ";
        }
        cout << endl;
    }
    //condition: first element A must be 0
    if (A[N-1]==1){
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
    }
    int segStart = 0;
    for (int i=N-1;i>=0;i--){
        if (i+1<N && A[i]==1 && A[i+1]==0) segStart=i;
        if (A[i]==1 && (i-1<0 || A[i-1]==0)){
            int len = segStart-i+1;
            cout << len << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;
}

int main() {
    int T = 1;
    if (multi) cin >> T;
    for (int i=0;i<T;i++) solve();
    return 0;
}