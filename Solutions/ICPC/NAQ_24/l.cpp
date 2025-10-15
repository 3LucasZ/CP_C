#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
typedef long double ld;
const char nl = '\n';

int R, C;
int sz = 0;
bool good = false;
pair<int, int> dest;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int hextoi(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    else if (hex >= 'a' && hex <= 'f')
    {
        return 10 + (hex - 'a');
    }
    else
    {
        return -1;
    }
}

bool valid_snake(vector<pair<int, int>> snake)
{
    vector<vector<bool>> vis(R, vector<bool>(C));
    for (auto p : snake)
    {
        if (vis[p.first][p.second])
            return false;
        vis[p.first][p.second] = true;
    }
    return true;
}

bool snake_win(vector<pair<int, int>> snake)
{
    vector<vector<bool>> vis(R, vector<bool>(C));
    for (auto p : snake)
    {
        vis[p.first][p.second] = true;
    }
    queue<pair<int, int>> ff;
    ff.push(snake.front());
    while (!ff.empty())
    {
        pair<int, int> p = ff.front();
        ff.pop();
        for (int k = 0; k < 4; k++)
        {
            pair<int, int> p2 = {p.first + dx[k], p.second + dy[k]};
            if (p2.first < 0 || p2.first >= R || p2.second < 0 || p2.second >= C || vis[p2.first][p2.second])
                continue;
            vis[p2.first][p2.second] = true;
            ff.push(p2);
        }
    }
    return vis[dest.first][dest.second];
}

void dfs(vector<pair<int, int>> snake, int moves)
{
    if (snake_win(snake))
    {
        good = true;
    }
    if (moves == sz + 2)
        return;

    snake.pop_back();
    pair<int, int> head = snake.front();
    snake.insert(snake.begin(), {-1, -1});
    for (int k = 0; k < 4; k++)
    {
        pair<int, int> head2 = {head.first + dx[k], head.second + dy[k]};
        if (head2.first < 0 || head2.first >= R || head2.second < 0 || head2.second >= C)
            continue;
        snake[0] = head2;
        if (valid_snake(snake))
            dfs(snake, moves + 1);
    }
}

int main()
{
    cin >> R >> C;
    vector<pair<int, int>> snake(16);
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            if (s[j] == '.')
                continue;
            else if (s[j] == 'A')
            {
                dest = {i, j};
            }
            else
            {
                snake[hextoi(s[j])] = {i, j};
                sz = max(sz, hextoi(s[j]) + 1);
            }
        }
    }
    if (sz <= 2)
    {
        cout << "1" << endl;
        return 0;
    }
    snake.resize(sz);
    dbg(snake, dest);
    dfs(snake, 0);
    if (good)
    {
        cout << "1" << nl;
    }
    else
    {
        cout << "0" << nl;
    }
}