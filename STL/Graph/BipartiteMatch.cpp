#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const char nl = '\n';

int m, n;

bool bpm(vector<vector<bool>> &bpGraph, int u, vector<bool> &seen, vector<int> &matchR)
{
    for (int v = 0; v < n; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

vector<int> maxBPM(vector<vector<bool>> &bpGraph)
{
    vector<int> matchR(n, -1);
    int result = 0;
    for (int u = 0; u < m; u++)
    {
        vector<bool> seen(n);
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return matchR;
}

int main()
{
    vector<vector<bool>> bpGraph(m, vector<bool>(n));
    vector<int> matchR = maxBPM(bpGraph);
    vector<int> match(m);
    for (int i = 0; i < n; i++)
    {
        if (matchR[i] > -1)
        {
            match[matchR[i]] = i;
        }
    }
}