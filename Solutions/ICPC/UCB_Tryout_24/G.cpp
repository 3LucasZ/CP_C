#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

int N;
unordered_multiset<int> h;
int main() {
    cin >> N;
    for (int i=0;i<N;i++){
        int x;
        cin >> x;
        h.insert(x);
    }

    ll best =1e18;
    for (int i=0;i<=1e6+10;i++){
        h.erase(i);
        best = min((unsigned long long) best, (long long) i+h.size());
    }
    
    cout << best << nl;
}