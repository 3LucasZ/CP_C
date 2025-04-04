// https://open.kattis.com/contests/nasouth24d1open/problems
// https://open.kattis.com/problems/welcomesign?editresubmit=17063945
#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main() {
    int r, c; cin >> r >> c;
    int shift = 0;
    for (int i=0;i<r;i++){
        string s; cin >> s;
        int k = (c-s.size())/2;
        if ((c-s.size())%2==1) {
            if (shift) k++;
            shift = 1-shift;
        }
        for (int i=0;i<k;i++) cout << ".";
        cout << s;
        for (int i=0;i<c-s.size()-k;i++) cout << ".";
        cout << nl;
    }
}