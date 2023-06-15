#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	for(int i=m+n-1;i>=n;i--){
		swap(arr1[i],arr1[i-n]);
	}
	int i=n;
	int j=0;
	int k=0;
	while(i<m+n && j<n){
		if(arr1[i]<=arr2[j]){
			arr1[k]=arr1[i];
			k++;
			i++;
		}
		else{
			arr1[k]=arr2[j];
			k++;
			j++;
		}
	}
	while(j<n){
		arr1[k]=arr2[j];
		k++;
		j++;
	}
	while(i<n+m){
		arr1[k]=arr1[i];
		k++;
		i++;
	}
	return arr1;
}