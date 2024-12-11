#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n = 1000000;
int m = 500;

int divisors(int x){
    int ret = 1;
    for (int i=2;i*i<=x;i++){
        int g = 1;
        while (x%i==0){
            g++;
            x/=i;
        }
        ret *= g;
    }
    if (x!=1) ret *= 2;
    return ret;
}
int main() {
    cout << divisors(28) << endl;
    for (int i=1;i<=n;i++){
        int j = i*(i+1)/2;
        if (divisors(j)>m){
            cout << j << endl;
            break;
        }
    }
}