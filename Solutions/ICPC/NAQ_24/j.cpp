#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
pair<int, int> red_frac(pair<int, int> frac)
{
    int x1 = frac.first * 3;
    int x2 = frac.second;
    while (x1 > x2)
    {
        x1 -= x2;
    }
    return {x1, x2};
}
vector<pair<int, int>> red_point(vector<pair<int, int>> point)
{
    for (int i = 0; i < 3; i++)
    {
        point[i] = red_frac(point[i]);
    }
    return point;
}

bool bad_frac(pair<int, int> &frac)
{
    int x1 = frac.first;
    int x2 = frac.second;
    return x2 < 3 * x1 && 3 * x1 < 2 * x2;
}
bool bad_point(vector<pair<int, int>> &point)
{
    int cnt = 0;
    for (auto frac : point)
        cnt += bad_frac(frac);
    return cnt >= 2;
}
bool check(vector<pair<int, int>> &point, int L)
{
    dbg(point, L);
    if (L == 0)
        return true;
    if (bad_point(point))
    {
        return false;
    }
    else
    {
        point = red_point(point);
        return check(point, L - 1);
    }
}
int main()
{
    int L;
    vector<pair<int, int>> point(3);
    cin >> L >> point[0].first >> point[0].second >> point[1].first >> point[1].second >> point[2].first >> point[2].second;
    bool ans = check(point, L);
    if (ans)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}