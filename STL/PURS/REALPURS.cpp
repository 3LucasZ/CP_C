#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class PURS {
    public:
        int size;
        vector<ll> tree;
        vector<ll> val;
        PURS (int n){
            init(n);
        }
        void init(int n){
            size = 1;
            while (size < n) size *= 2;
            tree = vector<ll>(2*size+1);
            val = vector<ll>(n+1);
        }
        void add (int k, int x){
            set(k,tree[k+size-1]+x);
        }
        void set(int k, long x){
            val[k]=x;
            k+=size-1;
            tree[k]=x;
            for (k/=2;k>=1;k/=2) tree[k]=tree[2*k]+tree[2*k+1];
        }
        long sum(int a, int b) {
            a+=size-1; b+=size-1;
            long ret = 0;
            while (a<=b){
                if (a%2==1) ret+=tree[a++];
                if (b%2==0) ret+=tree[b--];
                a/=2;
                b/=2;
            }
            return ret;
        }
};