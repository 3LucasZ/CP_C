#include <bits/stdc++.h>
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

int main()
{   
    // TODO: parse m, n from input
    vector<vector<bool>> bpGraph (m, vector<bool>(n));
    // TODO: fill bpGraph where bpGraph[u][v] true if u->v edge exists
    // Extracting the bp match: match[i] is the match of LHS person i
    vector<int> matchR = maxBPM(bpGraph);
    vector<int> match(m);
    for (int i=0;i<n;i++){
        if (matchR[i]>-1){
            match[matchR[i]] = i;
        }
    }
}