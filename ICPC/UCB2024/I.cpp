#include <bits/stdc++.h>
#include "debug.cpp"
using namespace std;
typedef long long ll;
const char nl = '\n';

int m, n;

// A DFS based recursive function 
// that returns true if a matching
// for vertex u is possible
bool bpm(vector<vector<bool>> &bpGraph, int u, vector<bool> &seen, vector<int> &matchR) {
    // Try every job one by one
    for (int v = 0; v < n; v++) {
        // If applicant u is interested in job v and v is not visited
        if (bpGraph[u][v] && !seen[v]) {
            // Mark v as visited
            seen[v] = true; 
            // If job 'v' is not assigned to an 
            // applicant OR previously assigned 
            // applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in 
            // the above line, matchR[v] in the following 
            // recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                dbg(v,u);
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number
// of matching from M to N
vector<int> maxBPM(vector<vector<bool>> &bpGraph) {
    // An array to keep track of the 
    // applicants assigned to jobs. 
    // The value of matchR[i] is the 
    // applicant number assigned to job i,
    // the value -1 indicates nobody is
    // assigned.
    vector<int> matchR(n, -1);
 
    // Count of jobs assigned to applicants
    int result = 0; 
    for (int u = 0; u < m; u++)
    {
        // Mark all jobs as not seen 
        // for next applicant.
        vector<bool> seen(n);
 
        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            // dbg(u, matchR[u]);
            result++;
    }
    return matchR;
}
 
// Driver Code
unordered_map<ll, int> numToId;
unordered_map<int, ll> idToNum;
unordered_map<int, pair<ll,ll>> idToPair;
int getId(ll num){
    if (!numToId.count(num)){
        numToId[num] = numToId.size();
    }
    idToNum[numToId[num]] = num;
    return numToId[num];
}

int main()
{   
    cin >> m; n = 3*m;
    dbg(m,n);
    vector<vector<bool>> bpGraph (m, vector<bool>(n));
    for (int i=0;i<m;i++){
        ll a, b; cin >> a >> b;
        ll a1 = a+b;
        ll a2 = a-b;
        ll a3 = a*b;
        dbg(a,b,a1,a2,a3);
        bpGraph[i][getId(a1)]=true;
        bpGraph[i][getId(a2)]=true;
        bpGraph[i][getId(a3)]=true;
        idToPair[i]={a,b};
    }
    dbg(idToPair);
    dbg(numToId);
    dbg(idToNum);
    for (int i=0;i<m;i++){
        dbg(bpGraph[i]);
    }
    vector<int> matchR = maxBPM(bpGraph);
    int ansCount = 0;
    dbg(matchR);
    vector<int> ans(m);
    for (int i=0;i<n;i++){
        if (matchR[i]>-1){
            ans[matchR[i]] = i;
            ansCount++;
        }
    }
    dbg(ansCount);
    if (ansCount < m){
        cout << "impossible" << nl;
        return 0;
    }
    dbg(ans);

    for (int i=0;i<m;i++){
        ll a = idToPair[i].first;
        ll b = idToPair[i].second;
        ll c = idToNum[ans[i]];
        char op = '*';
        if (a+b==c){
            op = '+';
        } else if (a-b==c){
            op = '-';
        }
        cout << a << " " << op << " " << b << " = " << c << nl;
    }
 
    return 0;
}