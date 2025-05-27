#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

class SegTree
{
    ll op(ll a, ll b)
    {
        return a + b;
    }

public:
    int sz;
    vector<ll> tree;

    SegTree(int n)
    {
        init(n);
    }
    SegTree(int n, vector<ll> arr)
    {
        init(n);
        for (int i = 1; i <= n; i++)
            tree[i + sz - 1] = arr[i];
        for (int i = sz - 1; i >= 1; i--)
            tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
    }
    void init(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree = vector<ll>(2 * sz + 1);
    }
    void update(int k, ll v)
    {
        k += sz - 1;
        tree[k] = op(tree[k], v);
        for (k /= 2; k >= 1; k /= 2)
            tree[k] = op(tree[2 * k], tree[2 * k + 1]);
    }
    ll query(int a, int b)
    {
        a += sz - 1;
        b += sz - 1;
        ll ret = 0;
        while (a <= b)
        {
            if (a % 2 == 1)
                ret = op(ret, tree[a++]);
            if (b % 2 == 0)
                ret = op(ret, tree[b--]);
            a /= 2;
            b /= 2;
        }
        return ret;
    }
};

ll invCnt(vector<int> &a)
{
    int n = a.size();
    SegTree st(n + 1);
    vector<int> q(n + 1);
    for (int i = 0; i < n; i++)
    {
        q[a[i]] = i + 1;
    }
    ll ret = 0;
    for (int i = 1; i <= n; i++)
    {
        ret += st.query(1, q[i]);
        st.update(q[i], 1);
    }
    return ret;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> a1;
    vector<int> a2;
    for (int i = 0; i < n; i += 2)
    {
        a1.push_back(a[i]);
        if (i + 1 < n)
            a2.push_back(a[i + 1]);
    }
    sort(begin(a1), end(a1));
    sort(begin(a2), end(a2));
    vector<int> b(n);
    for (int i = 0; i < a1.size(); i++)
    {
        b[2 * i] = a1[i];
    }
    for (int i = 0; i < a2.size(); i++)
    {
        b[2 * i + 1] = a2[i];
    }
    dbg(a);
    dbg(b);
    ll ai = invCnt(a);
    ll bi = invCnt(b);
    dbg(ai, bi);
    if (ai % 2 != bi % 2)
    {
        swap(b[n - 3], b[n - 1]);
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << nl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}