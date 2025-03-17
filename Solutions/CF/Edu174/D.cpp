#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

bool search(string s, int x) {
    int n = s.size();
    for (int i=0;i<n/2;i++){
        int j = n-1-i;
        // false: prefix does not fix (i, j)
        if (s[i]!=s[j] && i>x) return false;
    }
    //letters allowed
    vector<int> use(26);
    for (int i=0;i<=x;i++) use[s[i]-'a']++;
    //letters used
    for (int i=0;i<=x;i++) {
        int j = n-1-i;
        if (j<=x) break;
        // must use an s[j] at i
        if (s[i]!=s[j]) {
            use[s[j]-'a']--;
        } 
        // keep s[i] at i
        else {
            use[s[i]-'a']--;
        }
    }
    // dbg(x,use); 
    // false: not enough chars
    for (int i=0;i<26;i++) if (use[i]%2==1 || use[i]<0) return false;
    return true;
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    dbg(s,n);

    //find good already prefix
    int p = n/2-1;
    for (int i=0;i<n/2;i++){
        if (s[i]!=s[n-1-i]) {
            p = i-1;
            break;
        }
    }
    if (p==n/2-1) {
        cout << 0 << nl;
        return;
    }
    dbg(p);
    n -= 2*(p+1);
    s = s.substr(p+1, n);
    dbg(s,n);

    // run twice: forward and back
    int ans = n;
    for (int i=0;i<2;i++){
        // find must change prefix
        int lo=0; int hi=n-1;
        while (lo<hi){
            int mid = (lo+hi)/2;
            if (search(s, mid)) hi=mid;
            else lo=mid+1;
        }
        dbg(lo);
        ans = min(ans, lo);
        reverse(s.begin(), s.end());
    }
    cout << ans + 1 << nl;
}
int main() {
    int t; cin >> t; while (t--) solve();
}