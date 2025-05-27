#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

// binary search function
// searches for first occurence of element x in sorted array p, starting after ptr
int bin(vector<int> &p, int ptr, int x)
{
    // returns inf if x is not in p
    if (x > p[p.size() - 1])
        return inf;
    // run a standard binary search
    int lo = ptr;
    int hi = p.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (p[mid] < x)
        {
            lo = mid;
        }
        else if (p[mid] >= x)
        {
            hi = mid - 1;
        }
    }
    return lo + 1;
}
int main()
{
    // parse input
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // p1[i] is the number of 1s found in positions <= i. p2 is defined similarly.
    // this allows us to use our binary search function to find the jth 1 or 2 in "a" in O(nlogn) time.
    vector<int> p1(n + 1);
    vector<int> p2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];
        if (a[i] == 1)
            p1[i]++;
        else
            p2[i]++;
    }
    // store all pairs of {s, t} we find that work
    vector<pair<int, int>> ret;
    // the winner (player 1 or 2) must be the last one to win a serve in the entire record
    int winner = a[a.size() - 1];

    // iterate over all possible values of t
    // s will be uniquely determined based on t
    for (int t = 1; t <= n; t++)
    {
        // ptr is the end of the previous set
        int ptr = 0;
        // played is the number of sets played
        int played = 0;
        // s is the number of sets won by the winner
        int s = 0;
        // iterate over all sets
        while (true)
        {
            // binary search to find the t-th 1 and 2 after ptr
            int x1 = p1[ptr] + t;
            int end1 = bin(p1, ptr, x1);
            int x2 = p2[ptr] + t;
            int end2 = bin(p2, ptr, x2);
            // the minimum of these 2 values is the end of the set
            ptr = min(end1, end2);
            // if the remainder of the array does not have t 1s or 2s, this value of t does not work
            if (ptr == inf)
            {
                break;
            }
            // we have finished this set => update values
            played++;
            if (a[ptr] == winner)
                s++;
            // once all sets are found and confirmed to be valid, store the working {s, t} pair
            if (ptr == n)
            {
                if (s > played - s)
                {
                    ret.push_back({s, t});
                }
                break;
            }
        }
    }
    // print all working {s, t} found sorted lexicographically by s
    sort(begin(ret), end(ret));
    cout << ret.size() << "\n";
    for (auto r : ret)
    {
        cout << r.first << " " << r.second << "\n";
    }
}