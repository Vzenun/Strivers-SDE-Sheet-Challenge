#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int i=0;
	int j=0;
	while(true){
		i=arr[i];
		j=arr[arr[j]];
		if(i==j){
			break;
		}
	}
	j=0;
	while(i!=j){
		i=arr[i];
		j=[j];
	}
	return i;
}
