#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int f1=0;
	int f2=0;
	int answer;
	for(int i=0;i<n;i++){
		if(i==0){
			answer=arr[i];
		}
		if(arr[i]==0){
			f1=0;
			answer=max(arr[i],answer);
		}
		else{
			if(f1==0){
				f1=arr[i];
				answer=max(arr[i],answer);
			}
			else{
				f1*=arr[i];
				answer=max(f1,answer);
			}
		}
		if(arr[n-i-1]==0){
			f2=0;
			answer=max(arr[n-i-1],answer);
		}
		else{
			if(f2==0){
				f2=arr[n-i-1];
				answer=max(arr[n-i-1],answer);
			}
			else{
				f2*=arr[n-i-1];
				answer=max(f2,answer);
			}
		}
	}
	return answer;
}
