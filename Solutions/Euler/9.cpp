// SOL: bash
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 1000;
int main() {
    for (int i=1;i<=N;i++){
        for (int j=1;j<i;j++){
            for (int k=1;k<j;k++){
                if (k*k + j*j == i*i) {
                    if (k+j+i==1000){
                        cout << i*j*k << endl;
                    }
                }
            }
        }
    }
}