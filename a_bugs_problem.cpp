#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
vi adj[2001];
bool vis[2001];
int col[2001];

bool dfs(int node,int c)
{
    vis[node] = true;
    col[node] = c;
    for(auto child : adj[node])
    {
        if(vis[child] == false)
        {
            bool res = dfs(child,c^1);
            if(res == false)
                return false;
        }
        else
            if(col[child]==col[node])
                return false;
    }
    return true;
}

int main()
{
    int t,n,m,a,b; 
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n>>m;
        // resetting value
        for(int i=1; i<=n;i++)
            adj[i].clear() , vis[i] = false;
        // making adjacney list
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        // calling dfs for every #CC
        bool isWrite = true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
               bool res = dfs(i,0);
               if(res == false)
               {
                   isWrite = false;
                   break;
               }
            }
        }
        cout<<"Scenario"<<" #"<<tc<<":"<<endl;
        if(isWrite)
        {
            cout<<"No suspicious bugs found!"<<endl;
        }
        else
            cout<<"Suspicious bugs found!"<<endl;
    }
    return 0;
}