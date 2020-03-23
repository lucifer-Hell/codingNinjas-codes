#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

void BFSgetPath(int ** arr,int n,bool * visited,int sv ,int end,vector<int>& path ){
    // create a map to store conncetions
    map <int , int> m;
    
    bool found=false;
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
                                    if (i==end) found=true;
                                    m.insert(pair<int,int>(cv,i));
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

    
    if(found){

                    int preVal;
                    map<int,int> :: iterator it=m.end();
                    it--;
                    preVal=it->second;
                    cout<<it->second<<" ";
                   
                    for (;it!=m.begin();it--){
                        if (preVal=it->second){
                            cout<<it->first<<" ";
                            preVal=it->first;
                        }
                    }
                    cout<<sv;
    }
  
}





int main(){
    int e,n;
    int V,E;
    // vertices edges
    cin>>V>>E;
    n=V;
    e=E;

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
    int sv,end;
    cin>>sv;
    cin>>end;
   
     bool exists=false;
      // end will only be checked if it exists
    if (end<n) exists=true;     
     // get a vector 
    vector <int> path;
    vector <int>::iterator it;

    // make sure you pass it as refernece
   if (exists){
        BFSgetPath(arr,n,visited,sv,end,path);
           
                
            }
    else {
        // do nothing :(
    }

   

    
    return 0;   
    
}