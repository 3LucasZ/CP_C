#include<iostream>

using namespace std;

int main() {
    double pi = 3.1415;
    cout << pi << endl;
    double* pointerPi = &pi;
    cout << pointerPi << endl;
    pointerPi++;
    cout << pointerPi << endl;
    pointerPi+=1;
    cout << pointerPi << endl;
    cout << pointerPi+1 << endl;
    cout << &pi;
    return 0;
}