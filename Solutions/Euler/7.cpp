// SOL: sieve
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 10001;

int main() {
    int M = N*100;
    int found = 0;
    vector<bool> p(M+1, true);
    for (int i=2;i<=M;i++){
        if (p[i]) {
            found++;
            for (int j=2*i;j<=M;j+=i) p[j]=false;
        }
        if (found==N) {
            cout << i << endl;
            break;
        }
    }
    // cout << p[1] << p[2] << p[3] << p[4] << p[5] << p[6] << p[7] << endl;
}