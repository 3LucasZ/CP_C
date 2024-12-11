// BRUTE: sum1^2 - sum2 formulas
// ALT: linear system of equations
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 100;
int sum1(int n) {
    return n*(n+1)/2;
}
int sum2(int n) {
    return n*(n+1)*(2*n+1)/6;
}
int main() {
    cout << sum1(N)*sum1(N) - sum2(N) << endl;
}