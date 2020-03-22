#include <iostream>
using namespace std;

void DFS(int ** arr, int n ,bool * visited ,int sv){
    cout<<sv<<" ";
    
    // start vertex
    // find the connections 
    // apply dfs in them
    for (int i=0;i<n;i++){
        // ignore if vertex is same as start vertex
        if (i==sv) continue;
        // if vertex already visited ignore
        // if connection is there
        if(arr[i][sv]==1){
            // go to depth :)
            if (!visited[i]) { 
                visited[i]=true;
                DFS(arr,n,visited,i);

            }
            else continue;
        }
    }
}

int main(){
    int e,n;
    // vertices edges
    cin>>n>>e;

    // create adjacency matrix 
    int ** arr =new int * [n];
    for (int i=0;i<n;i++){
        arr[i]=new int [n];
    }
    // intialize with default value
    for(int i=0;i<n;i++)
        for (int j=0;j<n;j++)
                arr[i][j]=0;
      
    // create a visited vertices array
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    // get the edges input
    for (int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=1;
        arr[v2][v1]=1;

    }
    int sv=0;
    // base case 
    visited[sv]=true;
    DFS(arr,n,visited,sv);

    return 0;

}