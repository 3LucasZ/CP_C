#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

bool query(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    bool x;
    cin >> x;
    return x;
}
int main()
{
    vector<int> dr = {-1, 1, -1, 1};
    vector<int> dc = {-1, 1, 1, -1};
    int r = 3;
    int c = 3;

    // part 1: max 3 queries
    for (int i = 0; i < 3; i++)
    {
        int r2 = r + dr[i];
        int c2 = c + dc[i];
        bool q = query(r2, c2);
        if (q)
        {
            r = r2;
            c = c2;
            break;
        }
    }
    if (r == 3 && c == 3)
    {
        r += dr[3];
        c += dc[3];
    }
    dbg(r, c);

    // part 2: max 2 queries
    int q1 = query(r + 1, c);
    int q2 = query(r, c + 1);
    if (!q1)
        r--;
    if (!q2)
        c--;
    cout << "! " << r << " " << c << endl;
}