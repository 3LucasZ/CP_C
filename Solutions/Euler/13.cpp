#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

int n = 100;
int m = 50;
int main() {
    vector<string> ss(n);
    for (int i=0;i<n;i++){
        cin >> ss[i];
        reverse(all(ss[i]));
        // cout << ss[i] << endl;
    }

    vector<int> sum(m+1);
    for (int i=0;i<m;i++){
        for (string s : ss){
            sum[i] += (s[i]-'0');
        }
        while (sum[i]>=10) {
            sum[i]-=10;
            sum[i+1]+=1;
        }
        // cout << sum[i] << endl;
    }

    reverse(all(sum));
    for (int i=0;i<10;i++){
        cout << sum[i];
    }
    cout << endl;
    // copy paste only the first 10 characters lol :)
}