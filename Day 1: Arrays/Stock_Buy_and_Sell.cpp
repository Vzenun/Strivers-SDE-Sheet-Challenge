#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    vector<int> arr;
    for(int i=0;i<prices.size()-1;i++){
        arr.emplace_back(prices[i+1]-prices[i]);
    }
    long long ans=0;
    long long prev;
    for(int i=0;i<arr.size();i++){
        if(i==0){
            if(arr[i]>=0){
                ans=max(ans,(long long)arr[i]);
                prev=arr[i];
            }
            else{
                prev=0;
            }
        }
        else{
            if(prev+arr[i]>=0){
                ans=max(ans,prev+(long long)arr[i]);
                prev=arr[i]+prev;
            }
            else{
                prev=0;
            }
        }
    }
    return ans;
}