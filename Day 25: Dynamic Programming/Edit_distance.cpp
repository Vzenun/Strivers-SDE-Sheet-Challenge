int answer(string &s, string &t,int i,int j,vector<vector<int>> &dp){
    if(i==s.size() || j==t.size()){
        return s.size()-i+t.size()-j;
    }
    else if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        if(s[i]==t[j]){
            return dp[i][j]=answer(s,t,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=min(1+answer(s,t,i+1,j+1,dp),min(1+answer(s,t,i+1,j,dp),1+answer(s,t,i,j+1,dp)));
        }
    }

}
int editDistance(string s, string t)
{
    //write you code here
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
    return answer(s,t,0,0,dp);
}