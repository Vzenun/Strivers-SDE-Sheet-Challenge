#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        arr[i]=sum;
    }
    vector<pair<int,int>> ans;
    ans.emplace_back(0,-1);
    for(int i=0;i<arr.size();i++){
        ans.emplace_back(arr[i],i);
    }
    sort(ans.begin(),ans.end());
    int answer=0;
    int prev=-1;
    int ind=-1;
    for(int i=0;i<ans.size();i++){
        if(i==0){
        prev=ans[i].first;
        ind=ans[i].second;
        }
        else{
            if(ans[i].first==prev){
                answer=max(ans[i].second-ind,answer);
            }
            else{
                prev=ans[i].first;
                ind=ans[i].second;
            }
        }
    }
    return answer;
}