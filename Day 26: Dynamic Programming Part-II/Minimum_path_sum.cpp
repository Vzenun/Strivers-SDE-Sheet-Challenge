#include <bits/stdc++.h> 

int answer(int i,int j,vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){
    if(i==n-1 && j==m-1){
        return dp[i][j]=grid[i][j];
    }
    else if(i==n-1){
        return dp[i][j]=grid[i][j]+answer(i,j+1,grid,n,m,dp);
    }
    else if(j==m-1){
        return dp[i][j]=grid[i][j]+answer(i+1,j,grid,n,m,dp);
    }
    else if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        return dp[i][j]=min(grid[i][j]+answer(i+1,j,grid,n,m,dp),grid[i][j]+answer(i,j+1,grid,n,m,dp));
    }
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return answer(0,0,grid,grid.size(),grid[0].size(),dp);
}