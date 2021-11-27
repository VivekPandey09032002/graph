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

void printGraph(vector<int> ar[], int V)
{
    for(int i=0; i<=V; i++)
    {
        if(ar[i].size()>0)
        {
            cout<<i<<": ";
            for(auto x : ar[i])
            {
                cout<<"->"<<x;
            }
            cout<<endl;
        }
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
    printGraph(ar,8);
    return 0;
}