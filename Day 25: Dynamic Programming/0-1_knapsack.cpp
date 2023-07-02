int maxProfit(vector<int> &value, vector<int> &arr, int n, int w)
{
	// Write your code here
	int k=w;
	vector<int> prev_dp(k+1,0);
    vector<int> curr_dp(k+1,0);
	int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k+1;j++){
            if(i==0){
                if(j==0){
                    curr_dp[j]=0;
                }
                if(j==arr[i]){
                    curr_dp[j]=value[i];
					answer=max(curr_dp[j],answer);
                }
            }
            else{
                if(j+arr[i]<=k){
                    curr_dp[j+arr[i]]=max(curr_dp[j+arr[i]],prev_dp[j]+value[i]);
					answer=max(curr_dp[j+arr[i]],answer);
                }
            }
        }
		prev_dp=curr_dp;
    }
    return answer;
}