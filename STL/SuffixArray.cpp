// Tested on Codeforces and works 4/4/25

#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

// arr is pair(pair(suffix L MSB rank, suffix R LSB rank), suffix starting index)
void radix(vector<pair<pair<int,int>,int>> &arr) {
    int n = arr.size();
    // sort LSB, stable sort MSB
    for (int z=2;z>=1;z--){
        auto key = [&](pair<pair<int,int>,int> &x) {
			return z == 1 ? x.first.first : x.first.second;
		};
        // counting sort subroutine
        vector<int> freq(n);
        for (auto &x : arr) {
            freq[key(x)]++;
        }
        vector<int> s(n);
        for (int i=1;i<n;i++){
            s[i]=s[i-1]+freq[i-1];
        }
        vector<pair<pair<int,int>,int>> ret(n);
        for (auto &x : arr) {
            ret[s[key(x)]] = x;
            s[key(x)]++;
        }
        arr = ret;
    }
}
int main() {
    string str;
	cin >> str;
	str += '$';
	int n = str.size();
    dbg(n, str);

    vector<pair<pair<int, int>, int>> sufs(n);
    //base
    for (int i=0;i<n;i++){
        sufs[i] = {{str[i], str[i]}, i};
    }
    dbg(sufs);
    sort(begin(sufs),end(sufs));
    dbg(sufs);
    vector<int> ord(n);
    for (int i=1;i<n;i++){
        ord[sufs[i].second] = ord[sufs[i-1].second] + (sufs[i].first > sufs[i-1].first);
    }
    dbg(ord);
    //transitions
    for (int nxt=1;nxt<n;nxt*=2){
        for (auto &suf : sufs) {
            suf.first = {ord[suf.second], ord[(suf.second+nxt)%n]};
        }
        radix(sufs);
        for (int i=1;i<n;i++){
            ord[sufs[i].second] = ord[sufs[i-1].second] + (sufs[i].first > sufs[i-1].first);
        }
    }
    //solve
    for (int i=0;i<n;i++){
        cout << sufs[i].second << " ";
    }
    cout << nl;
}