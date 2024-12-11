// BRUTE: fib seq
// ALT: even fib seq
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 4e6;

int main() {
    int sum = 0;
    int a = 1;
    int b = 2;
    while (b < N) {
        if (b%2==0) sum += b;
        tie (a, b) = tuple(b, a+b);
        // cout << b << endl;
    }
    cout << sum << endl;
}