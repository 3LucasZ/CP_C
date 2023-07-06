#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int, int> pi;
//typedef pair<ll, ll> pll;

#define sz(x) (int)(x).size()
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
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
const bool multi = false;







const int HEIGHT = 30;

struct Trie {
    Trie *zero = nullptr;
    Trie *one = nullptr;
};

void insert(int x, Trie& root){
    Trie &cur = root;
    for (int layer=HEIGHT-1;layer>=0;layer--){
        int next = x&(1<<layer);
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
        int next = x&(1<<layer);
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
    Trie &cur = root;
    for (int layer=29;layer>=0;layer--){
        int next = x&(1<<layer);
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





void solve(){
    Trie root = Trie();
    unordered_set<int> layerGood[HEIGHT];
    unordered_multiset<int> seen;
    int multis = 0;

    int Q; 
    cin >> Q; 
    dbg(Q);

    for (int i=0;i<Q;i++){
        int type; cin >> type;
        if (type==1){
            int x; cin >> x;
            seen.insert(x);
            if (seen.count(x)==2){
                multis++;
            }

            Trie &cur = root;
            for (int layer=29;layer>=0;layer--){
                int next = x&(1<<layer);
                Trie child;
                if (next==0){
                    if (cur.zero==nullptr){
                        Trie ch = Trie();
                        cur.zero=&ch;
                        child=ch;
                    } else {
                        child=*cur.zero;
                    }
                }
                else {
                    if (cur.one==nullptr){
                        Trie ch = Trie();
                        cur.one=&ch;
                        child=ch;
                    } else {
                        child=*cur.one;
                    }
                }
                if (cur.one!=nullptr && cur.zero!=nullptr){
                    layerGood[layer].insert(x);
                }
                cur=child;
            }

        } else if (type==2){
            int x; cin >> x;
            seen.erase(x);
            if (seen.count(x)==1){
                multis--;
            }

            Trie &cur = root;
            Trie* path[HEIGHT];
            Trie* pathConj[HEIGHT];
            for (int layer=29;layer>=0;layer--){
                int next = x&(1<<layer);
                dbg(next);
                if (next==0){
                    cur=*cur.zero;
                    path[layer]=cur.zero;
                    pathConj[layer]=cur.one;
                }
                else {
                    cur=*cur.one;
                    path[layer]=cur.one;
                    pathConj[layer]=cur.zero;
                }
            }
            for (int layer=0;layer<HEIGHT;layer++){
                if (path[layer]->zero==nullptr || path[layer]->one==nullptr){
                    layerGood[layer].erase(x);
                }
                if (pathConj[layer]==nullptr){
                    delete(path[layer]);
                } else {
                    break;
                }
            }
        } else {
            if (multis>0){
                cout << 0 << nl;
            } else {
                for (int layer=0;layer>=HEIGHT;layer++){
                    if (layer==29){
                        cout << (1<<layer) << nl;
                    }
                    if (!layerGood[layer].empty()){
                        cout << (1<<layer) << nl;
                        break;
                    }
                }
            }
        }
        dbg(seen);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multi) cin >> T;
    for(int i=0;i<T;i++) {
        dbgM(i+1);
        solve();
    }
    return 0;
}