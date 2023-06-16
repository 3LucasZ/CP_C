#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    cout << *A.begin() << endl;
    cout << *--A.end() << endl;
    //cout << *(A.begin()-1) << endl; DOES NOT WORK
    cout << (++A.end() == A.end()?"true":"false") << endl;
    return 0;
}