// BRUTE: loop
// ALT: multiples of 11
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lo=100;
int hi=999;

bool isPal(int x){
    vector<int> d;
    while (x>0){
        d.push_back(x%10);
        x/=10;
    }
    for (int i=0;i<d.size();i++){
        if (d[i]!=d[d.size()-1-i]) return false;
    }
    return true;
}
int main() {
    int mx = 0;
    for (int a=lo;a<=hi;a++){
        for (int b=lo;b<=hi;b++){
            if (isPal(a*b)) mx = max(mx,a*b);
        }
    }
    cout << mx << endl;
}