// BRUTE: loop
// ALT: evens + rt(N)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N = 600851475143;

int main() {
    for (int i=2;i*i<N;i++){
        while (N%i == 0) N/=i;
    }
    cout << N << endl;
}