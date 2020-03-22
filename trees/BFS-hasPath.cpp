#include <iostream>
#include <queue>
using namespace std;

bool BFS(int ** arr,int n,bool * visited,int sv ,int end ){
     
    // create a queue
    queue <int> q;
    // push the start vertex
    q.push(sv);
    visited[sv]=true;
    int cv;
    
    // while queue is not empty
    while(!q.empty()) {
       
        
         cv=q.front();
        
        for (int i=0;i<n;i++){
                    // check if same as current vertex ignore
                    if (cv==i) continue;
                    // check if connection is there
                    if(arr[i][cv]==1){
                        // if already visited ignore
                                if (visited[i]==true) continue;
                                else{
                                    // mark i as visited 
                                    visited[i]=true;
                                    if (i==end) return true;
                                    q.push(i);

                                }
                    }
                    else{
                                continue;
                    }    
                }
         // finally print current vertex and pop it out
                //cout<<cv<< " ";
                q.pop();
        
    }

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
    int sv,dest;
    cout <<"Origin :";cin>>sv;
    cout<<"Destination:";cin>>dest;

    // print the bfs
    if(BFS(arr,n,visited,sv,dest)) cout<<"Path Found";
    else cout<<"Path cannot be found";


 
    return 0;   
    
}