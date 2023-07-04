#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int> as;
	as.push_back(arr[k-1]);
	as.push_back(arr[n-k]);
	return as;
}