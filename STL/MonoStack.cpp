#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';
const ll inf = 2e18;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(unsigned int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x);
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '<'; __print(x.first); cerr << ", "; __print(x.second); cerr << '>';}
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

/*
You have to edit to specify:
is a<=b okay or is it strictly a<b?
1-indexing (default 0) or 0-indexing (default -1)?
*/
template<typename T>
vector<int> nxt(vector<T> v, function<bool (T, T)> cmp, bool left=true){
    stack<T> s; vector<int> ret(sz(v));
    if (left) for (int i=0;i<sz(v);i++){ //1a
            while (!s.empty() && cmp(v[i],v[s.top()]))s.pop();
            if (!s.empty()) ret[i]=s.top();
            else ret[i]=-1; //2a
            s.push(i);
        }
    else for (int i=sz(v)-1;i>=0;i--){ //1b
            while (!s.empty() && cmp(v[i],v[s.top()]))s.pop();
            if (!s.empty()) ret[i]=s.top();
            else ret[i]=sz(v); //2b
            s.push(i);
        }
    return ret;
}

int main() {
    vector<int> A = {9,3,2,5,4,1,7,7,5,9,3,4,6,2};
    dbg(A, sz(A));
    vector<int> res;
    res = nxt<int>(A, greater<int>());
    dbg(res);
    res = nxt<int>(A, greater<int>(),false);
    dbg(res);
    res = nxt<int>(A, less<int>());
    dbg(res);
    return 0;
}