//BRUTE: loop
//ALT: sum(3) + sum(5) - sum(15)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 1000;

int main() {
    int sum = 0;
    for (int i=1;i<N;i++){
        if (i%3==0 || i%5==0) {
            sum += i;
        }
    }
    cout << sum << endl;
}