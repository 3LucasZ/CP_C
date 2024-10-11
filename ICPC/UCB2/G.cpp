#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end()

int R, C, K;
vector<vector<char>> a;
int main() {
    cin >> R >> C >> K;
    a.resize(R, vector<char>(C, '_'));
    for (int i=0;i<K;i++){
        int ri, ci, rd, cd; cin >> rd >> cd >> ri >> ci;
        for (int r=ri;r<min(R, ri+rd);r++){
            for (int c=ci;c<min(C, ci+cd);c++){
                a[r][c] = 'a'+i;
            }
        }
    }
    for (int c=0;c<C;c++){
    for (int r=0;r<R;r++){
        cout << a[r][c];
    }
        cout << nl;
    }
}