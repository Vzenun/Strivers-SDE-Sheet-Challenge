#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &nums, int n)
{
	// Write your code here
	int max1=0;
    vector<int> dp(nums.size()+1,1);
    for(int i=0;i<nums.size();i++){
		dp[i]=nums[i];
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(nums[i]+dp[j],dp[i]);
            }
        }
        //cout<<dp[i]<<endl;
        max1=max(dp[i],max1);
    }
    return max1;
}