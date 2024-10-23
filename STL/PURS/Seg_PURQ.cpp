#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';


const ll MOD = 1e9+7;













class SegTree {
    ll op(ll a, ll b){
        return a+b;
    }
    public:
        int sz;
        vector<ll> tree;
        
        SegTree (int n){
            init(n);
        }
        SegTree(int n, vector<ll> arr){
            init(n);
            for (int i=1;i<=n;i++) tree[i+sz-1]=arr[i];
            for (int i=sz-1;i>=1;i--)tree[i]=op(tree[i*2],tree[i*2+1]);
        }
        void init(int n){
            sz = 1; while (sz < n) sz *= 2;
            tree = vector<ll>(2*sz+1);
        }
        void update(int k, ll v){
            k+=sz-1;
            tree[k]=op(tree[k],v);
            for (k/=2;k>=1;k/=2) tree[k]=op(tree[2*k],tree[2*k+1]);
        }
        ll query(int a, int b) {
            a+=sz-1; b+=sz-1;
            ll ret = 0;
            while (a<=b){
                if (a%2==1) ret=op(ret,tree[a++]);
                if (b%2==0) ret=op(ret,tree[b--]);
                a/=2; b/=2;
            }
            return ret;
        }
};
string to_string(SegTree x) {vector<ll> v; for (int i=0;i<=x.sz;i++) v.push_back(x.query(i,i)); return to_string(v);}

int main() {
    SegTree purs(8);
    purs.update(4,2);
    purs.update(6,3);
    dbg(purs.query(1,8));
    dbg(purs);

    return 0;
}