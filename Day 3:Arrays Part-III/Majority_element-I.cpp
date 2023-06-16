#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int i=0;
	int answer=-1;
	int count=0;
	while(i<n){
		if(i==0){
			answer=arr[i];
			count++;
		}
		else{
			if(answer==arr[i]){
				count++;
			}
			else{
				if(count==0){
					answer=arr[i];
					count++;
				}
				else{
					count--;
				}
			}
		}
		i++;
	}
	int ct=0;
	for(int i=0;i<n;i++){
		if(arr[i]==answer){
			ct++;
		}
	}
	if(ct>(n/2)){
		return answer;
	}
	else{
		return -1;
	}
}