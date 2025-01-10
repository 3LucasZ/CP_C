#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

template<class T>
class SegTree {
    public:
        int sz;
        vector<T> tree;
        SegTree (int n){
            init(n);
        }
        SegTree(int n, vector<T> a){
            init(n);
            for (int i=1;i<=n;i++) tree[i+sz-1]=a[i];
            for (int i=sz-1;i>=1;i--) tree[i]=tree[i*2]+tree[i*2+1];
        }
        void init(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree = vector<T>(2*sz+1);
        }
        void set(int k, T v){
            k+=sz-1;
            tree[k]=v;
            for (k/=2;k>=1;k/=2) tree[k]=tree[2*k]+tree[2*k+1];
        }
};
const int INF = 1E9;
struct Obj {
    int min1, max1, min2, max2, x1, x2;
    Obj() : min1(INF), max1(-INF), min2(INF), max2(-INF), x1(0), x2(0) {}
    Obj(int i, int x) : min1(x-i), max1(x-i), min2(x+i-1E5), max2(x+i-1E5), x1(0), x2(0) {}
};
Obj operator+(const Obj &a, const Obj &b) {
    Obj res;
    res.min1 = min(a.min1, b.min1);
    res.max1 = max(a.max1, b.max1);
    res.min2 = min(a.min2, b.min2);
    res.max2 = max(a.max2, b.max2);
    res.x1 = max({a.x1, b.x1, b.max1-a.min1});
    res.x2 = max({a.x2, b.x2, a.max2-b.min2});
    return res;
}
void solve() {
    int n, q; cin >> n >> q;
    SegTree<Obj> st(n);
    for (int i=1;i<=n;i++) {
        int x; cin >> x;
        st.set(i, {i, x});
    }
    auto ans = [&] () {
        return max(st.tree[1].x1, st.tree[1].x2);
    };
    cout << ans() << endl;
    for (int i=0;i<q;i++){
        int p, x; cin >> p >> x;
        st.set(p, {p, x});
        cout << ans() << endl;
    }
}
int main() {
    int t; cin >> t; while (t--) {
        solve();
    }
}