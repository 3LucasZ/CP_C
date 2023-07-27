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












int main() {
    auto x = {5,4}; // "initializer list"

    auto p1 = pair(6,'3'); dbg(p1); // auto OP
    auto p2 = make_pair("good morning",9); dbg(p2); // before pair() was introduced
    pair<int,int> p3 = {5,4}; dbg(p3); // {} trick

    auto t1 = tuple(1,22.0,"yay");  //extend to tuples!
    auto t2 = tuple(1,2.9,"hi");
    tuple<int,ld,string> t3 = {6,0.2,"hi"};

    int a;
    ld b;
    string c;
    tie(a,b,c) = t3; //tie
    dbg(a,b,c);
    int u1 = 1;
    int u2 = 2;
    int u3 = 3;
    dbg(u1,u2,u3);
    tie(u1,u2,u3) = tuple(u1+u2,u2+u3,u1+u3);
    dbg(u1,u2,u3);

    //emplace back
    vector<pair<int,int>> v;
    v.emplace_back(3,4);
    v.push_back(pair(5,5));
    dbg(v);

    return 0;
}