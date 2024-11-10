#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

int n, m, s, p, q;
vector<bool> src;
vector<bool> tar;

int solve(int l, int r) { // page number
    int on = 0;
    int off = 0;
    int diff = 0;
    for (int i=l;i<=r;i++){
        if (tar[i]) on++;
        if (!tar[i]) off++;
        if (tar[i]!=src[i]) diff++;
    }
    return min({1+on,1+off,diff});
}

int main() {
    cin >> n >> m >> s >> p >> q;
    src.resize(n+1);
    for (int i=0;i<p;i++){
        int x; cin >> x;
        src[x] = true;
    }
    tar.resize(n+1);
    for (int i=0;i<q;i++){
        int x; cin >> x;
        tar[x] = true;
    }
    dbg(n, m, s, p, q);
    dbg(src);
    dbg(tar);

    int ans = 0;
    int page = 0;
    int a = s; int b = s;
    for (int l=1;l<=n;l+=m){
        int r = min(n, l+m-1);
        dbg(l,r);
        int moves = solve(l, r);
        ans += moves;
        dbg(moves);
        // see whats the first and last page that needs changing
        page++;
        if (moves>0) {
            a = min(a, page);
            b = max(b, page);
        }
    }
    dbg(a,b);
    ans += (b-a)+min(s-a, b-s);
    cout << ans << nl;
}