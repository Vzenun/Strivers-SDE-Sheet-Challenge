#include<bits/stdc++.h>
vector<vector<int> > ans2;
void kom(vector<int> ans,vector<int> & num,int i1,int sum,int k){
	if(i1<num.size()){
		int prev=-1;
		for(int i=i1;i<num.size();i++){
			if(prev!=num[i] && sum<=k){
				prev=num[i];
				sum+=num[i];
				ans.emplace_back(num[i]);
				if(sum==k){
					ans2.emplace_back(ans);
				}
				kom(ans,num,i+1,sum,k);
				ans.pop_back();
				sum-=num[i];
			}
		}
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int> ans;
    if(target==0){
        ans2.emplace_back(ans);
    }
    kom(ans,arr,0,0,target);
    vector<vector<int>> a1=ans2;
    ans2.clear();
    return a1;
}
