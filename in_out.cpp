#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> adj[100001];
int vis[100001];
int in[100001];
int out[10001];
int timer = 1;

void dfs(int node)
{
    vis[node] = 1; 
    in[node] = timer++;
    for(int child : adj[node])
    {
        if(vis[child] == 0)
            dfs(child);
    }
    out[node] = timer++;
}



int main(){
	int n,m,a,b;
	cin>>n>>m;
	// creating adj list
	for(int i=1; i<=m; i++)
		cin>>a>>b , adj[a].pb(b) , adj[b].pb(a);
	// for all connected component
	for(int i=1; i<=n; i++){
		if(vis[i]==false){
			dfs(i); 
		}	
	}

    // in timer
    cout<<"In timer"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<in[i]<<" ";
    }
    // out timer
    cout<<"\nOut timer"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<out[i]<<" ";
    }

	return 0;
}
