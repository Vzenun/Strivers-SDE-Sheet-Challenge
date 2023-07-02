int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> curr_dp(n+1,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            if(i==0){
                if(j==0){
                    curr_dp[0]=0;
                }
                if(j-(i+1)>=0 && curr_dp[j-(i+1)]!=-1){
                    curr_dp[j]=curr_dp[j-(i+1)]+price[i];
                }
            }
            else{
                if(j==0){
                    curr_dp[0]=0;
                }
                if(j-(i+1)>=0 && curr_dp[j-(i+1)]!=-1){
                    curr_dp[j]=max(curr_dp[j-(i+1)]+price[i],curr_dp[j]);
                }
            }
        }
    }
    return curr_dp[n];
}
