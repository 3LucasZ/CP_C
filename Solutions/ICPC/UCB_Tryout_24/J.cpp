#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

void solve(){
    //move #1
    cout << "3 1 3 6" << endl;
    while (true) {
        string action; cin >> action;
        if (action == "GAME") return;
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int R1 = 6-r1;
        int C1 = 7-c1;
        int R2 = 6-r2;
        int C2 = 7-c2;
        cout << R2 << " " << C2 << " " << R1 << " " << C1 << endl;
    }
}

int main(){
    int T; cin >> T;
    for (int i=0;i<T;i++){
        solve();
    }
}