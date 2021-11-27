#include <bits/stdc++.h>
using namespace std;
/*

        1
        |
        2
       / \
      7   8 -- 6
      \  /
        5

*/
void addEdge(vector<int> ar[], int u, int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}

void dfs(vector<int> ar[], vector<bool> & visited, int V,int i)
{
    
    cout<<V<<" ";
    visited[V] = true;
    for(auto x : ar[V])
    {
        if(visited[x]==false)
            dfs(ar,visited,x,i+1);
    }
    
}
int main()
{   
    int N=8;
    vector <int> ar[N+1];
    addEdge(ar,1,2);
    addEdge(ar,2,7);
    addEdge(ar,2,8);
    addEdge(ar,8,6);
    addEdge(ar,7,5);
    addEdge(ar,8,5);  
    vector<bool> visited (N+1,false);
    dfs(ar,visited,1,0);
    cout<<endl;
    return 0;
}