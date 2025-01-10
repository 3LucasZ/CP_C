#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;

int main() {
    int N = 1000; // 2^N
    int M = 400; // size of digits array
    vector<int> digits(M, 0);
    digits[0] = 1;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            digits[j]*=2;
        }
        for (int j=0;j<M;j++){
            digits[j+1]+=digits[j]/10;
            digits[j]%=10;
        }
    }
    int sum = 0;
    for (int i=0;i<M;i++){
        sum+=digits[i];
    }
    dbg(digits);
    cout << sum << endl;
}