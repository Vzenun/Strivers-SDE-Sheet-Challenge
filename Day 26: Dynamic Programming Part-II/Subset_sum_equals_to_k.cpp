#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> prev_dp(k+1,0);
    vector<int> curr_dp(k+1,0);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<k+1;j++){
            if(i==0){
                if(j==0 || (j==arr[i])){
                    curr_dp[j]=1;
                }
            }
            else{
                if(prev_dp[j]==1){
                    curr_dp[j]=1;
                    if(j+arr[i]<k){
                        curr_dp[j+arr[i]]=1;
                    }
                    else if(j+arr[i]==k){
                        return true;
                    }
                }
            }
        }
        prev_dp=curr_dp;
    }
    return false;
}