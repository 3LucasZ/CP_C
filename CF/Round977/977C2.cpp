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
#define dbgM(x) cout << "\e[34m" << "CASE: " << x << "\e[34m" << endl;
#else
#define dbg(x...)
#define dbgM(x) 
#endif

const bool multi = true;









int n, m, q;
vector<int> player; // player on position i
vector<int> position; //position of player i
vector<int> slideshow; // player who should be presenting slide i
vector<set<int>> playerSlides;

bool isBad(int i) { //is player on position i bad?
    return *playerSlides[i].begin() > *playerSlides[player[position[i]+1]].begin();
}

void solve(){
    cin >> n >> m >> q;
    player.resize(n+1); 
    position.resize(n+1);
    for (int i=1;i<=n;i++){
        cin >> player[i];
        position[player[i]]=i;
    }
    slideshow.resize(m+1); // player who should be presenting slide i
    for (int i=1;i<=m;i++){
        cin >> slideshow[i];
    }

    playerSlides.clear(); playerSlides.resize(n+1); // slides that player i has to present
    for (int i=1;i<=n;i++){ //initialize, so that every player presents fake INFINITY-th slide
        playerSlides[i].insert(m+100);
    }
    for (int i=1;i<=m;i++){
        playerSlides[slideshow[i]].insert(i);
    }
    set<int> bad; // players that are breaking the law
    for (int i=1;i<n;i++){ // loop over positions
        if (isBad(player[i])){
            bad.insert(player[i]);
        }
    }
    
    dbg(slideshow);
    dbg(playerSlides);
    dbg(bad);
    if (bad.size() == 0) cout << "YA" << nl;
    else cout << "TIDAK" << nl;

    for (int i=0;i<q;i++){
        int s, t; cin >> s >> t; // slideshow index, change to new player

        vector<int> checkChanged = {slideshow[s], player[position[slideshow[s]]-1], t, player[position[t]-1]};

        playerSlides[slideshow[s]].erase(s);
        playerSlides[t].insert(s);
        slideshow[s]=t;

        for (int x : checkChanged) {
            if (position[x] < n && bad.count(x) && !isBad(x)) {
                bad.erase(x);
            }
            if (position[x] < n && !bad.count(x) && isBad(x)) {
                bad.insert(x);
            }
        }

        dbg(slideshow);
        dbg(playerSlides);
        dbg(bad);
        if (bad.size() == 0) cout << "YA" << nl;
        else cout << "TIDAK" << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; if (multi) cin >> T;
    for(int i=0;i<T;i++) {dbgM(i+1);solve();}
    return 0;
}