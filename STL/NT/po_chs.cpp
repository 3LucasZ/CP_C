#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;

/*
INFO:
Cfg: MOD, MAXF
Stress tested: NO
Site: N/A
*/

ll MOD = 1e9+7;

//a ^ b
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

//a choose b
//M1: chs(N,K) = n!/[k!(n-k)!]
//M2: chs(N,K) = chs(N,K-1)*(N-K+1)/K
const int MAXF = 1000;
ll fact[MAXF+1];
ll invfact[MAXF+1];
void setupChs() {
    fact[0]=1; for (int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=po(fact[MAXF],MOD-2);
    for (int i=MAXF;i>=1;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll chs(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int main() {
    setupChs();
    dbg(po(2,10));
    dbg(po(2,20));
    dbg(po(2,100));

    dbg(po(10000, MOD-2));

    dbg(chs(5,2));
    dbg(chs(5,1));
    dbg(chs(5,0));

    dbg(chs(100, 50));
    dbg(chs(0,0));
    dbg(chs(0,-1));
    dbg(chs (100,500));
}