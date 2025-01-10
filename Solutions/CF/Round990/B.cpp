#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> cnt;
    for (int i=0;i<n;i++){
        cnt[s[i]]++;
    }

    char best = (*cnt.begin()).first;
    char worst = (*cnt.begin()).first;
    for (auto p : cnt){
        int i = p.first;
        if (cnt[i]>cnt[best]) best=i;
        if (cnt[i]<=cnt[worst]) worst=i;
    }
    dbg(s,best,worst);

    for (int i=0;i<n;i++){
        if (s[i]==worst) {
            s[i]=best;
            break;
        }
    }
    cout << s << endl;
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}