#include<bits/stdc++.h>
using namespace std;
/*

        1
        |
        2
       /  \
      3    4
          / \
         5   6
*/


void addEdge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
} 
 

void dfsDistance(vector<int> adj[],vector<bool> &visited, vector<int> &dist, int V)
{
    static int distance =0;
    visited[V] = true;
    for(auto x : adj[V])
    {
        if(visited[x] == false)
        {
            distance++;
            dist[x] = distance;
            dfsDistance(adj,visited,dist,x);
            distance--;
        }
    }
}

void dfs(vector<int> adj[],vector<bool> &visited,vector<int> node,int V,int y)
{
    if(V==y)
    {
        for(auto elm : node)
        {
            cout<<elm<<"->";
        }
        cout<<y<<endl;
        return;
    }
    node.push_back(V);
    visited[V] =true;
    for(auto x : adj[V])
    {
        if(visited[x]==false)
        {
            dfs(adj,visited,node,x,y);
        }
    }
    node.pop_back();

}
int main()
{
    int n=6;
    vector<int> adj[n+1];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    // distance
    vector<int> distance(n+1,0);
    //visited
    vector<bool> visited(n+1,false);   
    // cout<<"Enter source Node for Shortest Path: ";
    // int node; cin>>node;
    // dfsDistance(adj,visited,distance,node);
    // for(int i=1; i<n+1; i++)
    // {
    //     cout<<distance[i]<<" ";
    // }
    // cout<<endl;
    cout<<"Shortest Path b/w two nodes: ";
    int x,y; cin>>x>>y;
    vector<int> node;
    dfs(adj,visited,node,x,y);
    return 0;
}