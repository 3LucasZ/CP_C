#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

// number of elements in "a" STRICTLY LESS THAN key
int orderOf(vector<int> a, int key){
    int lo=-1; int hi=a.size()-1;
    while (lo<hi){
        int mid = (lo+hi+1)/2;
        if (a[mid] < key) lo=mid;
        else hi=mid-1;
    }
    return lo+1;
}

int main() {
    vector<int> a = {1,1,1,2,2,2,2,3,4,5,6};
    dbg(a);
    cout << "orderOf " << -100 << " is " << orderOf(a, 0) << nl;
    cout << "orderOf " << 0 << " is " << orderOf(a, 0) << nl;
    cout << "orderOf " << 1 << " is " << orderOf(a, 1) << nl;
    cout << "orderOf " << 2 << " is " << orderOf(a, 2) << nl;
    cout << "orderOf " << 3 << " is " << orderOf(a, 3) << nl;
    cout << "orderOf " << 100 << " is " << orderOf(a, 100) << nl;
}