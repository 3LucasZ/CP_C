#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#define dbgM(x) cout << "CASE: " << x << endl;
#else
#define dbg(x...)
#define dbgM(x)
#endif

const ll MOD = 1e9+7;
const bool multi = true;







const int HEIGHT = 30;
struct Trie {
    Trie *zero = nullptr;
    Trie *one = nullptr;
};
void __print(Trie x) {cerr << "{" << (x.zero==nullptr?"null":"full") << ", " << (x.one==nullptr?"null":"full") << "}";}
void insert(int x, Trie& root){
    cerr << "insert: ";
    Trie &cur = root;
    for (int layer=HEIGHT-1;layer>=0;layer--){
        int next = min(1,x&(1<<layer));
        cerr << next;
        if (next==0){
            if (cur.zero==nullptr){
                Trie ch = Trie();
                cur.zero=&ch;
                cur=ch;
            } else {
                cur=*cur.zero;
            }
        }
        else {
            if (cur.one==nullptr){
                Trie ch = Trie();
                cur.one=&ch;
                cur=ch;
            } else {
                cur=*cur.one;
            }
        }
    }
}
vector<Trie> get_chain(int x, Trie& root){
    Trie &cur = root;
    vector<Trie> ret;
    for (int layer=29;layer>=0;layer--){
        int next = min(1,x&(1<<layer));
        if (next==0){
            cur=*cur.zero;
        }
        else {
            cur=*cur.one;
        }
        ret.push_back(cur);
    }
    return ret;
}
bool search(int x, Trie& root){
    cerr << "search: ";
    Trie &cur = root;
    for (int layer=29;layer>=0;layer--){
        int next = x&(1<<layer);
        cerr << next;
        if (next==0){
            if (cur.zero==nullptr) return false;
            cur=*cur.zero;
        }
        else {
            if (cur.one==nullptr) return false;
            cur=*cur.one;
        }
    }
    return true;
}

int main() {
    Trie root = Trie();
    dbg(root);
    Trie ch0 = Trie();
    root.zero=&ch0;
    dbg(root);

    insert(128,root); cerr << endl;
    dbg(root);
    search(128,root); cerr << endl;
}