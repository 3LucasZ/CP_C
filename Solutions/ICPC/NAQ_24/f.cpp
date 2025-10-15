#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int main()
{
    ld x1, y1, x2, y2, a2;
    cin >> x1 >> y1 >> x2 >> y2 >> a2;

    ld a = a2 / 2;
    ld h = (x1 + x2) / 2;
    ld k = (y1 + y2) / 2;
    ld c = sqrt(pow(x1 - h, 2) + pow(y1 - k, 2));
    ld b = sqrt(pow(a, 2) - pow(c, 2));
    ld th = atan2(y1 - k, x1 - h);

    ld xt = atan(-b / a * tan(th));
    ld bx1 = h + a * cos(xt) * cos(th) - b * sin(xt) * sin(th);
    ld bx2 = 2 * h - bx1;

    ld yt = atan(b / (a * tan(th)));
    ld by1 = k + a * cos(yt) * sin(th) + b * sin(yt) * cos(th);
    ld by2 = 2 * k - by1;

    cout << min(bx1, bx2) << " " << min(by1, by2) << " " << max(bx1, bx2) << " " << max(by1, by2) << endl;
}