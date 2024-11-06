#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

ll a1, b1, a2, b2;
ll A1, B1, A2, B2;

vector<ll> gCount(201);
vector<ll> eCount(201);

int main() {
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> A1 >> B1 >> A2 >> B2;

    for (int i=a1;i<=b1;i++){
        for (int j=a2;j<=b2;j++){
            gCount[i+j]++;
        }
    }

    for (int i=A1;i<=B1;i++){
        for (int j=A2;j<=B2;j++){
            eCount[i+j]++;
        }
    }

    ll gBetter = 0;
    for (int i=1;i<=200;i++){
        for (int j=0;j<i;j++){
            gBetter += gCount[i]*eCount[j];
        }
    }

    ll eBetter = 0;
    for (int i=1;i<=200;i++){
        for (int j=0;j<i;j++){
            eBetter += eCount[i]*gCount[j];
        }
    }

    dbg(gBetter, eBetter);

    if (gBetter > eBetter) {
        cout << "Gunnar" << nl;
    } else if (eBetter > gBetter) {
        cout << "Emma" << nl;
    } else {
        cout << "Tie" << nl;
    }
}