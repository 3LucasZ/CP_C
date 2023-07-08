#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
const char nl = '\n';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ld x) {cerr << x;}
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

const bool multi = true;










ll get_bit(ll num, int bit){ return (num&(1<<bit))>0;}

string bin_to_str(ll bin, int len){
	stringstream tret;
	for (int i=0;i<len;i++) {tret<<(bin%2);bin>>=1;}
    string ret = tret.str(); reverse(all(ret));
	return ret;
}
ll str_to_bin(string bin){
    reverse(all(bin));
    ll ret = 0;
    for (int i=0;i<sz(bin);i++) ret+=((bin[i]-'0')<<i);
    return ret;
}


int main() {
    dbg(str_to_bin("110"));
    dbg(bin_to_str(6,3));
    dbg(nth_bit(6,2));
    dbg(nth_bit(6,1));
    dbg(nth_bit(6,0));
    return 0;
}