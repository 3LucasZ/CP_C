#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

// generate all perms of the list of objects given
template <typename T>
vector<vector<T>> genPerms(vector<T> s) {
    vector<vector<T>> perms;
    function<void(vector<T>, int)> genPerms;
    genPerms = [&] (vector<T> s, int idx) -> void {
        if (idx == s.size() - 1) {
            perms.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            swap(s[idx], s[i]);
            genPerms(s, idx + 1);
            swap(s[idx], s[i]);
        }
    };
    genPerms(s, 0);
    return perms;
}

int main() {
    dbg(genPerms<int>({1,2,3,4}));
    dbg(genPerms<int>({1,2,3,4}).size());
}