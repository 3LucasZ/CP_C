#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int main() {
    freopen("in.txt","w",stdout);
    ll n = 100000;
    cout << n << endl;
    srand(time(0));
    for (int i=0;i<n;i++) {
        ll b = rand()%1000+2;
        cout << b*b << endl;
    }
}