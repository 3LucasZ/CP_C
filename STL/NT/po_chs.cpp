#include <iostream>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

//a ^ b
ll po(ll a,ll b){
    if (b==0) return 1;
    else if (b%2==0) return po(a*a%MOD,b/2);
    else return a*po(a,b-1)%MOD;
}

//a choose b
const int MAXF = 1000;
ll fact[MAXF+1];
ll invfact[MAXF+1];
void setupChs() {
    fact[0]=1; for (int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=po(fact[MAXF],MOD-2);
    for (int i=MAXF;i>=1;i--) invfact[i-1]=invfact[i]*i%MOD;
}
ll chs(int n, int k) {
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

int main() {
    setupChs();
    cout << po(2,10) << endl;
    cout << po(2,100) << endl;
    cout << po(2,1000) << endl;

    cout << chs(5,2) << endl;
    cout << chs(5,1) << endl;
    cout << chs(5,0) << endl;
    return 0;
}