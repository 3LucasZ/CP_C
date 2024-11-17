#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) x.begin(), x.end()

// generate all perms of the list of strings given
vector<vector<string>> perms;
void genPerms(vector<string> s, int idx){
    if (idx == s.size() - 1) {
        perms.push_back(s);
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        swap(s[idx], s[i]);
        genPerms(s, idx + 1);
        swap(s[idx], s[i]);
    }
}

string worst = string(50,'z');
string ans = string(50,'z');
// generate every combination you can form from a permutation
void genCombos(vector<string> ss) {
    if (ss.size()==1){
        //new combo found! process it: update the answer.
        if (ss[0].size() < ans.size()){
            ans = ss[0];
        }
        else if (ss[0].size() == ans.size()){
            ans = min(ans, ss[0]);
        }
        return;
    }
    //pick a word to combine
    for (int k=0;k<ss.size()-1;k++)
    //pick a suffix to match
    for (int i=1; i<=min(ss[0+k].size(),ss[1+k].size()); i++){
        if (ss[0+k].substr(ss[0+k].size()-i) == ss[1+k].substr(0,i)) {
            //recursively get new combos
            vector<string> comb;
            for (int j=0;j<ss.size();j++) {
                if (j==0+k) comb.push_back(ss[0+k]+ss[1+k].substr(i));
                else if (j==1+k) continue;
                else comb.push_back(ss[j]);
            }
            genCombos(comb);
        }
    }
}

int main() {
    int n; cin >> n;
    vector<string> ss(n);
    for (int i=0;i<n;i++){
        cin >> ss[i];
    }
    dbg(n,ss);
    genPerms(ss, 0);
    dbg(perms);
    for (vector<string> perm : perms) {
        genCombos(perm);
    }
    if (ans == worst) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
    }
}