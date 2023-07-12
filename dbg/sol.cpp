#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp(a,b) make_pair(a,b)
#define vi vector<int>
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define vp vector<pair<int,int> >
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define dom 998244353
#define sl(a) (int)a.length()
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define pii pair<int,int> 
#define mini 2000000000000000000
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const long double pi = acos(-1);
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
//primes for hashing 937, 1013
template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}
vector<int> adj[200005];
int vis[200005],c[200005],t;
pii p[200005];
void dfs(int x)
{
    vis[x]=1;
    c[x]=1;
    int i;
    p[x]=mp(t,t);
    t++;
    fr(i,sz(adj[x]))
    {
        if(!vis[adj[x][i]])
        {
            dfs(adj[x][i]);
            c[x]+=c[adj[x][i]];
            p[x].S=p[adj[x][i]].S;
        }
    }
}
void shikhar7s(int cas)
{
    int n,i;
    cin>>n;
    t=0;
    fr(i,n)
    {
        vis[i]=0;
        adj[i].clear();
    }   
    int x,y;
    fr(i,n-1)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0);
    int ans=0;
    fr(i,sz(adj[0]))
    {
        int x=c[adj[0][i]];
        x=(x*(x-1))/2;
        ans+=x;
    }
    cout<<ans<<" ";
    int s=0,ss=0,got=1;
    y=-1;
    fr(i,sz(adj[0]))
    {
        int x=c[adj[0][i]];
        if(p[adj[0][i]].F<=p[1].F&&p[adj[0][i]].S>=p[1].S)
        {
            y=adj[0][i];
            x-=c[1];
        }
        if(adj[0][i]!=y)
            got+=x;
        s+=x;
        x*=x;
        ss+=x;
    }
    ans=(s*s-ss)/2;
    ans+=s;
    cout<<ans<<" ";
    i=2;
    int l=0,r=1,j,b=0;
    while(i<n)
    {
        if((p[i].F<=p[l].F&&p[i].S>=p[l].S)||(p[i].F<=p[r].F&&p[i].S>=p[r].S))
        {
            cout<<0<<" ";
            i++;
            continue;
        }
        if(!l)
        {
            int f=2;
            ss=c[r];
            if(p[r].F<=p[i].F&&p[r].S>=p[i].S)
            {
                f=1;
                ss-=c[i];
            }
            if(!(p[y].F<=p[i].F&&p[y].S>=p[i].S))
            {
                ans=1;
                fr(j,sz(adj[0]))
                {
                    int x=adj[0][j];
                    if(x==y)
                        continue;
                    int su=c[x];
                    if(p[x].F<=p[i].F&&p[x].S>=p[i].S)
                    {
                        f=0;
                        su-=c[i];
                    }
                    ans+=su;
                }
            }
            else
                ans=got;
            ans*=ss;
            cout<<ans<<" ";
            if(!f)
                l=i;
            else if(f==1)
                r=i;
            else
            {
                i++;
                b=1;
                break;
            }
        }
        else
        {
            int f=2;
            s=c[l];
            ss=c[r];
            if(p[l].F<=p[i].F&&p[l].S>=p[i].S)
            {
                f=0;
                s-=c[i];
            }
            if(p[r].F<=p[i].F&&p[r].S>=p[i].S)
            {
                f=1;
                ss-=c[i];
            }
            ans=s*ss;
            cout<<ans<<" ";
            if(!f)
                l=i;
            else if(f==1)
                r=i;
            else
            {
                i++;
                b=1;
                break;
            }
        }
        i++;
    }
    if(!b)
        cout<<1<<" ";
    else
    {
        while(i<=n)
        {
            cout<<0<<" ";
            i++;
        }
    }
    cout<<endl;
}
signed main()
{
    fast;
    //freopen("output.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int t=1;
    cin>>t;
    int cas=1;
    while(cas<=t)
    {
    //cout<<"Case #"<<cas<<": ";
    shikhar7s(cas);
    cas++;
    }
    return 0;
}