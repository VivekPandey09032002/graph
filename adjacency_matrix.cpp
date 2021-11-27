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

void printMatrix( const vector< int >  matrix[], int n)
{   int start = 1;
    for(int i=1; i<n+1; i++)
    {   cout<<start<<" ";
        for(int j=1; j<n+1; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
        start++;    
    }
}

void addEdge(vector< int> matrix[], int u, int v)
{
    matrix[u][v]=1;
    matrix[v][u]=1;
}
int main()
{
    // creating a 2d matrix of size = max_element(inputs) => 6
    int arr [] = {1,2,7,8,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = *max_element(arr,arr+size);
    vector< int > ar[n+1]; // 0 to n element
    for(int i=0; i<n+1; i++)
        for(int j=0; j<n+1; j++)
            ar[i].push_back(0);
    // print heading
    cout<<"  ";
    for(int i=1; i<=n; i++)
        cout<<i<<" ";
    cout<<endl;   
    
    // inserting edge
    addEdge(ar,1,2);
    addEdge(ar,2,7);
    addEdge(ar,2,8);
    addEdge(ar,8,6);
    addEdge(ar,7,5);
    addEdge(ar,8,5);
    printMatrix(ar,n);
    return 0;
}