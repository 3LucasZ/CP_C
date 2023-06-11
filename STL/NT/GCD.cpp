#include <iostream>
using namespace std;
typedef long long ll;

/*
INFO:
Cfg: N/A
Stress tested: NO
Site: N/A
*/

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    cout << gcd(1000, 250) << endl;
    ll a = 47L*2500*6956343;
    ll b = 47L*1000;
    cout << gcd(a, b) << endl;
}