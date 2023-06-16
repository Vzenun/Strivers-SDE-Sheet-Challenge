#include <bits/stdc++.h> 
int num_paths(int i,int j,int m,int n,vector<vector<int>> & dp){
	if(i==m-1 && j==n-1){
		return dp[i][j]=1;
	}
	else if(i>=m || j>=n){
		return 0;
	}
	else if(dp[i][j]!=-1){
		return dp[i][j];
	}
	else{
		return dp[i][j]=num_paths(i+1,j,m,n,dp)+num_paths(i,j+1,m,n,dp);
	}
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> a(n,-1);
	vector<vector<int>> dp(m,a);
	return num_paths(0,0,m,n,dp);
}