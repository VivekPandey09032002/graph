#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> adj[10001];
int vis[10001];
int dis[10001];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dis[node] = 0;
    while(!q.empty())
    {   
        
        int current = q.front();
        // cout<<current<<" ";
        q.pop();

        for(int child : adj[current])
        {
            if(vis[child]  == 0){
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[current] + 1;
            }
        }
    }
}


int main()
{
    int t; cin>>t;
    int n,m,a,b;
    while (t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)   adj[i].clear() , vis[i] = 0;
        while(m--)  cin>>a>>b, adj[a].pb(b) , adj[b].pb(a);
        bfs(1);
        cout<<dis[n]<<endl;
    } 
    return 0;
}