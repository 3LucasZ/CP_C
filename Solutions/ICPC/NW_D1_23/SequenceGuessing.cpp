#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    // total numbers - X's
    cout << 100001 - 33333 << endl;
    vector<int> used(33333 + 1); // 0 -> unused OR i -> the slot in box that's used

    // get query
    while (true) {
        int q; cin >> q;
        //give up
        if (q==-1) {
            cout << 0 << endl;
            for (int i=1;i<=33333;i++) {
                if (used[i]) {
                    cout << used[i] << endl;
                } else {
                    cout << 3*i-1 << endl;
                }
                cout << 3*i << endl;
            }
            cout << 100000 << endl;
            break;
        } 
        //query
        else {
            if (q==0) {
                cout << 1 << endl;
            } else if (q==100000) {
                cout << 100001 - 33333 << endl;
            } else {
                int id = (q+2)/3;
                if (q%3==0) {
                    cout << 2*id + 1 << endl;
                }
                else if (used[id]) {
                    cout << 2*id << endl;
                } else {
                    cout << -1 << endl;
                    used[id] = 3*id-q%3;
                }
            }
        }
    }
}