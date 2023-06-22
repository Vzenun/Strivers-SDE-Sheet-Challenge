vector<int> ans;
void kom(vector<int> & num,int i1,int sum){
	if(i1<num.size()){
		for(int i=i1;i<num.size();i++){
			sum+=num[i];
			ans.emplace_back(sum);
			kom(num,i+1,sum);
			sum-=num[i];
		}
	}
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	ans.emplace_back(0);
	kom(num,0,0);
	vector<int> num2=ans;
	sort(num2.begin(),num2.end());
	ans.clear();
	return num2;
}