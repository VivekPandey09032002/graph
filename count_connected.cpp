#include <bits/stdc++.h>
using namespace std;
/*

     1
     |
     5
   /   \
   2    6 --4
    \  /
      8

    3
     \
      \
       7

    9
     \
     10
     /
    11    
*/
void addEdge(vector<int> ar[], int u, int v)
{
    ar[u].push_back(v);
    ar[v].push_back(u);
}

void dfs(vector<int> ar[], vector<bool> & visited, int V)
{
    
    // cout<<V<<" ";
    visited[V] = true;
    for(auto x : ar[V])
    {
        if(visited[x]==false)
            dfs(ar,visited,x);
    }
    
}
int main()
{   
    int N=11;
    vector <int> ar[N+1];
    addEdge(ar,1,5);
    addEdge(ar,5,2);
    addEdge(ar,5,6);
    addEdge(ar,6,8);
    addEdge(ar,6,4);
    addEdge(ar,2,8);
    // other cc
    addEdge(ar,3,7);
    //other cc
    addEdge(ar,9,10);
    addEdge(ar,10,11);
    vector<bool> visited (N+1,false);
    int count=0;
    for(int i=1; i<=N; i++)
    {
        if(visited[i]==false){
            dfs(ar,visited,i);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}