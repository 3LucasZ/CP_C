// Tested on Codeforces and works 4/4/25
// https://codeforces.com/edu/course/2/lesson/2/4/practice/contest/269119/problem/A

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    string str = "";
    for (int i=0;i<n;i++){
        if (a[(i+1)%n] > a[i]) str += '0';
        else str += '1';
    }
	// str += '$';
	// int n = str.size();
    dbg(n, str);

    vector<pair<pair<int, int>, int>> sufs(n);
    // base
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
    // transitions
    for (int nxt=1;nxt<n;nxt*=2){
        for (auto &suf : sufs) {
            suf.first = {ord[suf.second], ord[(suf.second+nxt)%n]};
        }
        radix(sufs);
        for (int i=1;i<n;i++){
            ord[sufs[i].second] = ord[sufs[i-1].second] + (sufs[i].first > sufs[i-1].first);
        }
    }
    for (int i=0;i<n;i++) dbg(sufs[i].second, str.substr(sufs[i].second)+str.substr(0,sufs[i].second));
    // construct LCP
    vector<int> p(n); // rank of suffix i
    for (int i=0;i<n;i++){
        p[sufs[i].second] = i;
    }
    dbg(p);
    int k = 0;
    vector<int> lcp(n); // lcp of suffix i and j where j is right before i in the sort
    for (int i=0;i<n;i++){
        if (p[i]==0) continue;
        int j = sufs[p[i]-1].second;
        while (str[(i+k)%n]==str[(j+k)%n] && k<n) k++;
        lcp[i] = k;
        k = max(k-1, 0);
    }
    for (int i=0;i<n;i++) dbg(sufs[i].second, str.substr(sufs[i].second)+str.substr(0,sufs[i].second), lcp[sufs[i].second]);
    for (int i=0;i<n;i++) {
        int ans = lcp[i]+1;
        if (p[i]<n-1) {
            int j = sufs[p[i]+1].second;
            ans = max(ans, lcp[j]+1);
        }
        if (ans > n) ans = -1;
        cout << ans << nl;
    }
}