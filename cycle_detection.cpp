#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> adj[100001];
int vis[100001];

bool dfs(int node,int parent){
	vis[node] = 1; // true
	for(int child : adj[node]){
		if(vis[child] == 0)  /// no visited 
			if(dfs(child,parent) == true)	return true;   // cycle detected stop recursion
		else
			if(child != parent)	return true;  
			// already visited then parent should be him only if not cycle
	}
	// no cycle detected
	return false;
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
			bool ans = dfs(i,-1); // no parent
			cout<<"cycle detected in #" <<i<<" undirected graph ";
			if(ans)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}	
	}

	return 0;
}
