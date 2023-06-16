#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long int num=n*(n+1)/2;
	long long int sum=0;
	int x=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		x=x^arr[i];
	}
	for(int i=0;i<n;i++){
		x=x^(i+1);
	}
	int pos=0;
	int nk=1;
	//cout<<(nk&x)<<endl;
	while((nk&x)!=nk){
		nk=nk<<1;
		//cout<<nk<<endl;
		pos++;
	}
	//cout<<x<<" "<<nk<<endl;
	int y=0;
	x=0;
	for(int i=0;i<n;i++){
		if((nk&arr[i])==nk){
			y=y^arr[i];
		}
		else{
			x=x^arr[i];
		}
	}
	for(int i=0;i<n;i++){
		if((nk&(i+1))==nk){
			y=y^(i+1);
		}
		else{
			x=x^(i+1);
		}
	}
	if(sum>num){
		pair<int,int> ans=make_pair(min(x,y),max(x,y));
		return ans;
	}
	else{
		pair<int,int> ans=make_pair(max(x,y),min(x,y));
		return ans;
	}
}
