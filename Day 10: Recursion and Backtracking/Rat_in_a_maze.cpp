#include <bits/stdc++.h> 
void kom(vector<vector<int>> arr,vector<vector<int>> k,vector<vector<int>> &ans,int i,int j,int n){
    if(i==n-1 && j==n-1){
        vector<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s.emplace_back(k[i][j]);
            }
        }
        ans.push_back(s);
        return;
    }
    if(arr[i][j]!=-1){
        arr[i][j]=-1;
        if(i+1<n){
            if(arr[i+1][j]==1){
                k[i+1][j]=1;
                kom(arr,k,ans,i+1,j,n);
                k[i+1][j]=0;
            }
        }
        if(j+1<n){
            if(arr[i][j+1]==1){
                k[i][j+1]=1;
                kom(arr,k,ans,i,j+1,n);
                k[i][j+1]=0;
            }
        }
        if(i-1>=0){
            if(arr[i-1][j]==1){
                k[i-1][j]=1;
                kom(arr,k,ans,i-1,j,n);
                k[i-1][j]=0;
            }
        }
        if(j-1>=0){
            if(arr[i][j-1]==1){
                k[i][j-1]=1;
                kom(arr,k,ans,i,j-1,n);
                k[i][j-1]=0;
            }
        }
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> k(maze.size(),vector<int>(maze.size(),0));
    if(maze[0][0]==0){
        return ans;
    }
    else{
        k[0][0]=1;
        kom(maze,k,ans,0,0,n);
        return ans;
    }
}