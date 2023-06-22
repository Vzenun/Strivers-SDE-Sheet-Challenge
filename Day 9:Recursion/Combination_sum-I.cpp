vector<vector<int> > ans2;
void kom(vector<int> ans,vector<int> & num,int i1,int sum,int k){
	if(i1<num.size()){
		for(int i=i1;i<num.size();i++){
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

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> ans;
    if(k==0){
        ans2.emplace_back(ans);
    }
    kom(ans,arr,0,0,k);
    vector<vector<int>> a1=ans2;
    ans2.clear();
    return a1;
}