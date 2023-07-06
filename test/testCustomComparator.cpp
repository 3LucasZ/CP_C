//Link on Custom Comparators: https://usaco.guide/silver/sorting-custom?lang=cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue> 
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
template<class T> using pq = priority_queue<T>;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
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
#else
#define dbg(x...)
#endif

int main() {
    vector<int> A = {0,4,5,6,67,7,7,7,7,7,7};
    dbg(A);
    sort(all(A));
    dbg(A);
    sort(all(A),greater<int>());
    dbg(A);
    sort(all(A),less<int>());
    dbg(A);
  
    vector<pair<int,int>> B = {};
    for (int i=0;i<10;i++){
         B.push_back(pair{rand()%1000, rand()%1000});
    }
    dbg(B);
    sort(all(B));
    dbg(B);
    sort(all(B),greater<pair<int,int>>());
    dbg(B);
    sort(all(B),[](pair<int,int> a, pair<int,int> b){
        return b.first/b.second - a.first/a.second;
    });
    sort(all(B),[&](pair<int,int> a, pair<int,int> b){
        return a.first/a.second > b.first/b.second;
    });
    dbg(B);

    vector<int> cost = {4,5,6,3,3,24,5,1,7,8};
    vector<int> ord = {0,1,2,3,4,5,6,7,8,9};
    sort(all(ord),[&](int a, int b){ //NOTE: & lets you use outside scope.
        return cost[a] < cost[b];
    });
    dbg(ord);

    return 0;
}