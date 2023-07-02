#include<bits/stdc++.h>
long long answer(int i,int n,int *arr,int value,vector<vector<long>> &dp){
    if(i==n){
        if(value==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(dp[i][value]!=-1){
        return dp[i][value];
    }
    else if(value==0){
        return dp[i][value]=1;
    }
    else{
        if(value-arr[i]>=0){
            return dp[i][value]=answer(i,n,arr,value-arr[i],dp)+answer(i+1,n,arr,value,dp);
        }
        else{
            return dp[i][value]=0;
        }
    }
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    sort(denominations,denominations+n);
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return (long)answer(0,n,denominations,value,dp);
}