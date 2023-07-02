#include <bits/stdc++.h> 
int answer(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(j-i==1){
        return dp[i][j]=arr[i]*arr[i+1]*arr[i+2];
    }
    else if(i==j){
        return dp[i][j]=0;
    }
    else{
        int ans=INT_MAX;;
        for(int k=i+1;k<=j;k++){
            ans=min(ans,answer(i,k-1,arr,dp)+answer(k,j,arr,dp)+arr[i]*arr[k]*arr[j+1]);
        }
        return dp[i][j]=ans;
    }
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return answer(0,N-2,arr,dp);
}