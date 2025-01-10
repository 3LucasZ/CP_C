#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const ll MOD = 1e9+7;

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
    int val = 0;
};
Obj operator+(const Obj &a, const Obj &b) {
    Obj res;
    res.val = a.val + b.val;
    return res;
}
int main() {
    SegTree<Obj> purs(8);
    for (int i=1;i<=8;i++){
        purs.set(i,{i});
    }
    cout << purs.query(1,8).val << nl;
}