#include <iostream>
#include <vector>
using namespace std;

bool DFS(int ** arr, int n ,bool * visited ,int sv,int end,vector<int> & path){
    //cout<<sv<<" ";
    visited[sv]=true;

    if (sv==end){
       // cout<<"Comparing "<<sv<<" with "<<end<<endl;
        // path found
        path.push_back(sv);
       
        return true;
    }
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
                //visited[i]=true;
                // if path found push current sv also
                if(DFS(arr,n,visited,i,end,path)){
                    path.push_back(sv);
                    return true;
                };

            }
            else continue;
        }
    }
    // if path couldn't be found
    return false;
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
    int sv;
    int end;
    bool exists=false;
    cin>>sv;
    cin>>end;
    // end will only be checked if it exists
    if (end<n) exists=true;     


    // get a vector 
    vector <int> path;
    vector <int>::iterator it;
    // make sure you pass it as refernece
   if (exists){
         if(DFS(arr,n,visited,sv,end,path)) 
            {
                // iterate through each element of vector
              // cout<<"Path Size:"<<path.size()<<endl;
                for ( it=path.begin();it!=path.end();it++){
                    cout<<*it<<" ";
                }
                
            }
    else {
        // do nothing :(
    }

   }
   
    return 0;

}