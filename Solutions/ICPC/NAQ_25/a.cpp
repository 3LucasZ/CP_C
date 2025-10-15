#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    int r, g, b;
    int cr, cg, cb;
    cin >> r >> g >> b >> cr >> cg >> cb;
    r -= cr;
    g -= cg;
    b -= cb;
    r = max(r, 0);
    g = max(g, 0);
    b = max(b, 0);
    int crg, cgb;
    cin >> crg >> cgb;
    int rt = min(r, crg);
    r -= rt;
    crg -= rt;
    int bt = min(b, cgb);
    b -= bt;
    cgb -= bt;
    int gt = min(g, crg + cgb);
    g -= gt;
    dbg(r, g, b);
    if (r == 0 && g == 0 && b == 0)
    {
        cout << rt + gt + bt << nl;
    }
    else
    {
        cout << -1 << nl;
    }
}