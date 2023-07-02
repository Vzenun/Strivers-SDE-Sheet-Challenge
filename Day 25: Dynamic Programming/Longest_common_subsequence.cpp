#include<bits/stdc++.h>
int answer(int i,int j,string &s,string &t,vector<vector<int>> &dp){
	if(i==s.size() || j==t.size()){
		return 0;
	}
	else if(dp[i][j]!=-1){
		return dp[i][j];
	}
	else{
		if(s[i]==t[j]){
			return dp[i][j]=1+answer(i+1,j+1,s,t,dp);
		}
		else{
			return dp[i][j]=max(answer(i,j+1,s,t,dp),answer(i+1,j,s,t,dp));
		}
	}
}
int lcs(string s, string t)
{
	//Write your code here
	vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
	return answer(0,0,s,t,dp);
}