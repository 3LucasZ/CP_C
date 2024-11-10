#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end()


int n;
vector<vector<int>> tree;
int stallers;
vector<int> leaves;
string str;

void dfs(int node, int par){
    if (tree[node].size()==1 && node!=1){
        leaves.push_back(node);
    } else {
        if (node!=1 && str[node]=='?') stallers ++;
    }
    for (int child : tree[node]) {
        if (child!=par) dfs(child, node);
    }
}
void solve() {
    cin >> n;
    tree.clear(); tree.resize(n+1);
    stallers=0;
    leaves.clear();
    for (int i=0;i<n-1;i++){
        int u; int v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cin >> str; str = " "+str;

    dfs(1, 0);
    dbg(str, leaves, stallers);

    // Case 1: root is ?
    int num0=0; int num1=0; int numX=0;
    for (int leaf : leaves){
        num0+=str[leaf]=='0';
        num1+=str[leaf]=='1';
        numX+=str[leaf]=='?';
    }
    dbg(num0,num1,numX);
    int ans = 0;
    //Case 1
    if (str[1]=='?'){
        // Case A: take ?
        ans = max(num0, num1) + numX/2;
        // Case B: forfeit ? and stall
        if (stallers%2==1) ans = max(ans, min(num0, num1) + (numX+1)/2);
    }
    //Case 2
    else {
        int tk = str[1]=='0'?num1:num0;
        ans = tk + (numX + 1)/2;
    }
    
    cout << ans << nl;
}
int main() {
    int t; cin >> t; 
    while (t--)solve();
}