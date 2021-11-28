#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
vector<int> adj[10001];
bool vis[10001];
int col[10001];
//  check if graph is bipartite
void addEdge(int a, int b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}

bool dfs(int node, int c)
{
    vis[node] =1;
    col[c] = c;
    for(int child : adj[node])
    {
        if(vis[child] == 0)
        {
            if(dfs(child,c^1)==false)
                return false;

        }            
        else if(col[node] == col[child])
                return false;    

    }
    return true;
}


int main()
{
    addEdge(1,2);
    addEdge(1,6);
    addEdge(2,1);
    addEdge(2,3);
    addEdge(3,4);    
    addEdge(3,2);
    addEdge(4,3);
    addEdge(4,5);
    addEdge(5,6);
    addEdge(5,4);
    addEdge(6,1);
    addEdge(6,5);
    if(dfs(1,0)== true)
        cout<<"yes";
    else
        cout<<"no";    

    return 0;
}