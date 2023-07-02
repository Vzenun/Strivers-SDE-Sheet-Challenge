#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp;
    for(int i=0;i<n;i++){
        if(i==0){
            dp.push_back(arr[i]);
        }
        else{
            if(arr[i]>dp[dp.size()-1]){
                dp.push_back(arr[i]);
            }
            else{
                int a1=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
                dp[a1]=arr[i];
            }
        }
    }
    return dp.size();
}
