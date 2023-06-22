#include <bits/stdc++.h> 
vector<vector<int> > ans2;
void kom(vector<int> ans,vector<int> & num,int i1){
	if(i1<num.size()){
        int prev=-1;
		for(int i=i1;i<num.size();i++){
            if(prev!=num[i]){
                prev=num[i];
                ans.emplace_back(num[i]);
                ans2.emplace_back(ans);
                kom(ans,num,i+1);
                ans.pop_back();
            }
		}
	}
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    vector<int> ans;
    ans2.emplace_back(ans);
    kom(ans,arr,0);
    vector<vector<int>> a1=ans2;
    ans2.clear();
    return a1;
}