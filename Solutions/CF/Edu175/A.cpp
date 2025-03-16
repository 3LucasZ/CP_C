#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    vector<int> x(15);
    int a = 0;
    for (int i=0;i<15;i++) {
        if (i%3==i%5) a++;
        x[i] = a;
    }
    int t; cin >> t; while (t--){
        int n; cin >> n;
        cout << (n/15)*x[14] + x[n%15] << nl;
    }
}