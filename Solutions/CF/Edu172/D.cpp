#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

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
            for (int i=sz-1;i>=1;i--)tree[i]=tree[i*2]+tree[i*2+1];
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
        T query(int a, int b) {
            a+=sz-1; b+=sz-1;
            T ret;
            while (a<=b){
                if (a%2==1) ret = ret + tree[a++];
                if (b%2==0) ret = ret + tree[b--];
                a/=2; b/=2;
            }
            return ret;
        }
};
struct Obj {
    int lmax = 0;
    int rmin = 1e9+1;
};
Obj operator+(const Obj &a, const Obj &b) {
    Obj res = {};
    res.lmax = max(a.lmax, b.lmax);
    res.rmin = min(a.rmin, b.rmin);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> pairs(2*n+1);
    for (int i=1;i<=n;i++){
        cin >> pairs[i] >> pairs[n+i];
    }

    vector<int> ord;
    vector<bool> bad(n+1);
    for (int i=1;i<=n;i++) ord.push_back(i);
    sort(begin(ord), end(ord), [&](int a, int b){
        if (pairs[a]==pairs[b]) return pairs[a+n]<pairs[b+n];
        return pairs[a] < pairs[b];
    });
    for (int i=1;i<n;i++){
        if (pairs[ord[i]]==pairs[ord[i-1]] && pairs[ord[i]+n]==pairs[ord[i-1]+n]){
            bad[ord[i]] = true;
            bad[ord[i-1]] = true;
        }
    }
    dbg(pairs);

    vector<int> events(2*n+1);
    for (int i=1;i<=n;i++){
        events[2*i-1] = i;
        events[2*i] = i+n;
    }
    sort(events.begin() + 1, events.end(), [&](int a, int b){ //NOTE: & lets you use outside scope.
        if (pairs[a] == pairs[b]) {
            //both left 
            if (a <= n && b <= n) {
                // have same right => take smaller index
                if (pairs[a+n] == pairs[b+n]) return a < b;
                // else => take the one with a larger right
                return pairs[a+n] > pairs[b+n];
            }
            //both right
            if (a > n && b > n) {
                // have same left => take larger index
                if (pairs[a-n] == pairs[b-n]) return a > b;
                // else => take the one with a larger left
                return pairs[a-n] > pairs[b-n];
            }
            //one left and one right => take the left one
            return a < b;
        }
        return pairs[a] < pairs[b];
    });
    dbg(events);

    vector<int> ans(n+1);
    SegTree<Obj> st(n);
    int curId = 0;
    //index wrt to l for pair[i].left
    vector<int> li(n+1);
    for (int i=1;i<=2*n;i++){
        int event = events[i];
        // left
        if (event <= n) {
            curId++;
            st.set(curId, {pairs[event], pairs[n+event]});
            li[event] = curId;
        } 
        // right
        else {
            event -= n;
            int id = li[event];
            if (id > 0) {
                Obj obj = st.query(1, id-1);
                if (obj.rmin != 1e9+1 && obj.lmax !=0) {
                    ans[event] = (obj.rmin-obj.lmax+1) - (pairs[event+n]-pairs[event]+1);
                }
            }
            //remove event
            st.set(id, {});
        }
    }

    //ret
    for (int i=1;i<=n;i++){
        if (!bad[i]) {
            cout << ans[i] << nl;
        } else {
            cout << 0 << nl;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}