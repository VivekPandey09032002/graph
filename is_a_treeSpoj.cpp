#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
vector<int> adj[10001];
bool vis[10001];

void dfs(int node)
{   
    // cout<<node<<" ";
    vis[node] = true;
    for(auto child : adj[node])
    {
        if(vis[child] == false)
            dfs(child);
    }
}
int main()
{
    int n,e,a,b; cin>>n>>e;
    for(int i=1; i<=e; i++)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int cc_count = 0;
    for(int i=1; i<=n ; i++)
    {
        if(vis[i]==false)
            dfs(i), cc_count++ ;   
    }
    if(cc_count == 1 and n-e == 1)
        cout<<"YES";
    else
        cout<<"NO";    
    return 0;
}