#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';
#define all(x) (x).begin(), (x).end();

vector<int> dr = {0,0,1,-1, 1,1,-1,-1};
vector<int> dc = {1,-1,0,0, 1,-1,1,-1};

int N;
int B;
unordered_set<string> words;
vector<int> points = {0,0,0,1,1,2,3,5,11};
vector<string> board(4);
vector<vector<bool>> vis(4, vector<bool>(4));

bool hasWordOn(int r, int c, string word) {
    // dbg(r,c,word);
    if (r < 0 || r >= 4 || c < 0 || c >= 4) return false;
    if (word == "") return true;
    if (word[0] != board[r][c]) return false;
    if (vis[r][c]) return false;
    vis[r][c] = true;
    bool ret = false;
    for (int i=0;i<8;i++){
        int rr = r+dr[i]; int cc = c+dc[i];
        if (hasWordOn(rr, cc, word.substr(1,word.size()-1))) ret = true;
    }
    vis[r][c] = false;
    return ret;
}
bool hasWord(string word) {
    for (int r=0;r<4;r++){
        for (int c=0;c<4;c++){
            if (hasWordOn(r,c,word)) return true;
        }
    }
    return false;
}

void solve() {
    for (int i=0;i<4;i++){
        cin >> board[i];
    }
    dbg(board);

    int numWords = 0;
    int numPoints = 0;
    string best = "";
    for (auto word : words) {
        if (hasWord(word)) {
            numWords++;
            numPoints+=points[word.size()];
            if (word.size() > best.size() || (word.size() == best.size() && word < best)) {
                best = word;
            }
        }
    }
    cout << numPoints << " " << best << " " << numWords << nl;
}
int main() {
    cin >> N;
    for (int i=0;i<N;i++){
        string word; cin >> word; 
        words.insert(word);
    }
    dbg(words);
    cin >> B;
    for (int i=0;i<B;i++){
        solve();
    }
}