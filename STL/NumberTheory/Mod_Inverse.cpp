#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;

// REPLACE MOD WITH YOUR EXPERIMENT
ll MOD = 998244353;

// a ^ b
ll po(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return po(a * a % MOD, b / 2);
    else
        return a * po(a, b - 1) % MOD;
}

ll frac_to_mod(ll a, ll b)
{
    return a * po(b, MOD - 2) % MOD;
}
const int MAX_X = 1000;
unordered_map<int, pair<int, int>> mp;
void mod_to_frac(int x)
{
    auto it = mp.find(x);
    auto pr = (it == mp.end()) ? make_pair(0, 0) : it->second;
    cout << pr.first << "/" << pr.second << endl;
}
int main()
{
    for (int i = 1; i <= MAX_X; i++)
    {
        ll im = po(i, MOD - 2);
        for (int j = 1; j <= MAX_X; j++)
        {
            ll key = im * j % MOD;
            mp.insert({key, {j, i}});
        }
    }
    mod_to_frac(443664157);
}