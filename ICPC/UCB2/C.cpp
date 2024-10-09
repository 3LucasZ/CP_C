#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
const char nl = '\n';

string line = 
"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main() {
    string in; 
    while (getline(cin, in) && !in.empty()){
        dbg(in);
        for (int i=0;i<in.length();i++){
            if (in[i] == ' '){
                cout << " ";
            }
            for (int j=0;j<line.length();j++){
                if (in[i] == line[j]){
                    cout << line[j-1];
                }
            }
        }
        cout << nl;
    }
}